#include <ansi.h>
inherit SSERVER;

int curse(object me, object target)
{
	string msg;
	int duration;
	
	if(me->query("class")!="yinshi")
		return notify_fail("只有帝王谷弟子才能下鬼降。\n");
	
        if((int)me->query_skill("celecurse",1) < 150 )
                return notify_fail("鬼降需要150级通天降！\n");

	duration = me->query("timer/ghostcurse")-time()+ 300; // 5mins
        if (duration>0)
        	return notify_fail("鬼降耗费体能极大，需要休息"+(int)(duration/60+1)+"分钟。\n");
	
	if(me->query("kee") < 100 )
		return notify_fail("鬼降需要耗费100点气血！\n");
		
	write("你想拘谁的魂？");
	input_to( (: call_other, __FILE__, "select_target", me :));
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
                write("中止拘魂。\n");
                return;
        }

        ob = find_living(name);
	room = environment(me);
	me->receive_wound("kee",100);
	me->set_temp("last_damage_from","下降头过度累死了。\n");
        if( !ob || !me->visible(ob) || userp(ob) || present(ob, room)|| ob->is_ghost()
        	|| ob->query("no_curse") || ob->query("boss")){
		write("你无法感受到这个人的灵魂。\n");
		return; 
	}
        
        msg = HIW "$N双手向上一挥，一阵浓雾从地下卷出。。。。\n" ;
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
		new1->set("combat_exp", (new1->query("combat_exp"))*11/10);
		new1->set("chat_chance",0);
		new1->set("inquiry",0);
		new1->set("ghostcurse",1);
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
		new1->set("title",HIB "拘魂"NOR);
		msg +=  "浓雾似乎在$N身边渐渐地浓缩成一个黑影。。。。\n" NOR;
		new1->start_call_out((: call_other, __FILE__, "melt", new1 :), 300);
		me->set("timer/ghostcurse",time());
	}
	else
		msg += "浓雾立刻消失了。。。\n"NOR;
	message_vision(msg, me);
}

void melt(object ob)
{
	message_vision(WHT"$N渐渐的虚化，消失了。。。\n"NOR,ob);
	destruct(ob);
}

