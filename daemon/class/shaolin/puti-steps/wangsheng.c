// Silencer @ FY4 workgroup. Oct.2004
//	ghostcurse every 5min

#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
    	int skill,duration;
    	    	
    	if (me->query("class")!="shaolin")  
     		return notify_fail("唯有少林高僧才能使用『三途往生』\n");
     		    	
    	skill = me->query_skill("puti-steps", 1);
		if(skill < 150 || me->query_skill("zen",1)<140) 
			return notify_fail("『三途往生』至少需要150级菩提虚空步法和140级禅道！\n");
	 
    	duration = me->query("timer/wangsheng")-time()+ 300; // 5mins
        if (duration>0)
        	return notify_fail("『三途往生』耗费体能极大，需要休息"+(int)(duration/60+1)+"分钟。\n");
        	
        if( (int)me->query("force") < 400 )     
    		return notify_fail("『三途往生』需要耗费400点内力。\n");
    	if (userp(me))	me->add("force", -400);
	      		
     	write("请输入往生咒的对象名字：");
	input_to( (: call_other, __FILE__, "select_target", me :));
	
	me->perform_busy(2);
	return 1;
}

void select_target(object me, string name)
{
	mapping ob_list;
        object ob,new1;
	string msg;
	object room;
	string *list;
	object *inv;
	int i,HERE = 0;
        if( !name || name=="" ) {
                write("诵经停止。\n");
                return;
        }

        ob = find_living(name);
	room = environment(me);
	me->receive_wound("kee",100);
	me->set_temp("last_damage_from","念咒过度累死了。\n");

        if( !ob || !me->visible(ob) || userp(ob) || present(ob, room)|| ob->is_ghost()
        	|| ob->query("no_curse") || ob->query("boss")){
		write("你无法感受到这个人的灵气。\n");
		return; 
	}
        
        msg = HIW "$N双目低垂，神情庄重，缓缓前进三步，又退后两步，合十颂出往生之咒：
若问前生事 　今生受者是　 若问后世事　 今生做者是  ！\n" ;
    	if( ob_list = room->query("objects"))	{
		list = keys(ob_list);
		for(i=0;i<sizeof(list);i++)
			if(list[i] == base_name(ob) || list[i] == base_name(ob)+".c")
				{	HERE=1;
					break;
				}
		}
		
	if(HERE && random(10) >0 
		&& ob->query("combat_exp")<= me->query("combat_exp")*12/10
		&& ob->query("combat_exp")>= me->query("combat_exp")* 8/10
	) 
	{
		seteuid(geteuid(me));
		new1 = new(base_name(ob));
		new1->set("ghostcurse",1);
		new1->be_ghost(1);
		new1->set("combat_exp", (new1->query("combat_exp"))*11/10);
		inv = all_inventory(new1);
		for(i=0;i<sizeof(inv);i++)
		{
			if (inv[i]->query("money_id"))	
			{
				destruct(inv[i]);
				continue;
			}
			inv[i]->set("ghostcurse_item",1);
		}
			
		new1->move(room);	
		new1->set("title",HIB "归魂"NOR);
		msg +=  WHT"\n顷许，空地上白雾缭绕，隐隐出现了一个人影。\n" NOR;
		new1->start_call_out((: call_other, __FILE__, "melt", new1 :), 300);
		me->set("timer/wangsheng",time());
	}
	else
		msg += WHT"\n四周静悄悄的，什么也没有发生。\n"NOR;
	message_vision(msg, me);
}

void melt(object ob)
{
	message_vision(WHT"$N渐渐的虚化，消失了。。。\n"NOR,ob);
	destruct(ob);
}