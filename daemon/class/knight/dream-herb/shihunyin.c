// // Silencer @ FY4 workgroup. Oct.2004
#include <ansi.h>

int perform(object me, object target)
{
    	int skill,duration;
    	    	
    	if (me->query("class")!="knight")  
     		return notify_fail("唯有快活林弟子才能使用『失魂引』\n");
     		    	
    	skill = me->query_skill("dream-herb", 1);
		if(skill < 180) 
		return notify_fail("『失魂引』至少需要180级云梦五花锦！\n");
	 
    	duration = me->query("timer/shimeng")-time()+ 300; // 5mins
        if (duration>0)
        	return notify_fail("『失魂引』耗费体能极大，需要休息"+(int)(duration/60+1)+"分钟。\n");
        	     		
     	write("请输入失梦引的对象名字：");
		input_to( (: call_other, __FILE__, "select_target", me :));
	
		me->perform_busy(2);
		return 1;
}

void select_target(object me, string name)
{
	mapping ob_list;
        object ob,new1;
	string msg, cname;
	object room;
	string *list;
	object *inv, corpse;
	int i,HERE = 0;
        if( !name || name=="" ) {
                write("失魂引停止。\n");
                return;
        }

        ob = find_living(name);
		room = environment(me);

        if( !ob || !me->visible(ob) || userp(ob) || present(ob, room)|| ob->is_ghost()
        	|| ob->query("no_curse") || ob->query("boss")){
			tell_object(me,"你无法感受到此人的生气。\n");
			return; 
		}
        
        inv = all_inventory(room);
        for (i=0;i<sizeof(inv);i++)
        {
        	if(!inv[i]->is_corpse()) continue;
        	if(inv[i]->query("victim_id")!= name) continue;
        	corpse = inv[i];
        }
        
        if (!corpse)
        {
        	tell_object(me, "此人尸骨无存，无法使用失魂引。\n");
        	return;
        }
        
        if( (int)me->query("force") < 400 ) {     
    		tell_object(me,"『失魂引』需要耗费400点内力。\n");
    		return;
    	}
    	if (userp(me))	me->add("force", -400);
        
        cname = corpse->query("name");
        
        msg = HIG "$N"HIG"双手疾点，簇簇飞出几道绿烟，在"+cname+"的要害之处连击数掌，大喝一声，起 ！\n" ;
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
		new1->be_ghost(1);
		new1->set("ghostcurse",1);
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
		new1->set("title",HIG "药人"NOR);
		msg +=  WHT"\n"+cname+"的尸体抽搐了几下，忽然晃晃悠悠地站了起来。\n" NOR;
		new1->start_call_out((: call_other, __FILE__, "melt", new1 :), 300);
		me->set("timer/shimeng",time());
		destruct(corpse);
	}
	else
		msg += WHT"\n"+ cname+"的尸体抽搐了几下，又不动弹了。\n"NOR;
	message_vision(msg, me);
}


void melt(object ob)
{
	message_vision(WHT"$N忽然象稀泥般瘫倒在地,花成一滩血水。。\n"NOR,ob);
	destruct(ob);
}