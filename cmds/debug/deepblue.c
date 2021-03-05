// cat.c
#include <ansi.h>

inherit F_CLEAN_UP;

object env;
int damage;

int destroying(object me,object room,int n,int damage)
{
	object *inv;
	int i;	
	mapping exits;
	string *dirs, dest;
	object next_room;
	
	if(room!=env)
	{
		tell_room(room,HIB"\n深蓝的光芒犹如闪电般掠过！！！\n"NOR);
		tell_room(room,HIW"在场的一切都被扭曲，毁灭，仿佛犹如地狱降临一般！！！\n"NOR);
	}
	room->set("destroying",1);
	room->destroy_room();
	inv=all_inventory(room);
	for(i=0;i<sizeof(inv);i++)
	{
		if(!objectp(inv[i]))
			continue;
		if(inv[i]==me)
			continue;
		if(inv[i]->is_character())
		{
			message_vision(HIB"\n$N全身都为深蓝的光芒笼罩着！！\n"NOR,inv[i]);
			inv[i]->delete("resistance");
			inv[i]->receive_wound("kee",damage*(n+1));
			COMBAT_D->report_status(inv[i]);
			inv[i]->set_temp("last_damage_from",me);
		}
	}
        if( mapp(exits = room->query("exits")) ) 
	{
		dirs=keys(exits);
		for(i=0;i<sizeof(dirs);i++)
		{
			dest=room->query("exits/"+dirs[i]);
			if(!next_room=find_object(dest))
				next_room=load_object(dest);
			if(!objectp(next_room)) continue;
			if(next_room->query("destroying"))
				continue;
			if(!n) continue;
			destroying(me,next_room,n-1,damage);
		}
	}
	room->delete("destroying");
	return 1;
}
	
			
int begin_perform(object me)
{
	int n;

	
	message_vision(HIG"耀眼的光芒，犹如成千上万的蓝宝石齐放光彩，瞬间将周围万物卷入，
似缓实快的往外扩张，夹带强大能源的光波冲击著所经过的一切！！\n"NOR,me);
	n=me->query("deepblue_range");
	damage=me->query("sen");
//	if(n>10)
//		n=10;
	me->delete_temp("in_deepblue");
	me->set("gin",1);
	me->set("kee",1);
	me->set("sen",1);
	me->set("eff_gin",1);
	me->set("eff_kee",1);
	me->set("eff_sen",1);
	destroying(me,env,n,damage);
}
	
	
string *spelling_msg=({
 HIB"比大海更深沉的忧伤， \n"NOR,
 HIB"比天空更青蓝的悠远，\n"NOR,
 HIB"自九幽地渊之底复现， \n"NOR,
HIB"我以自身鲜血为誓， \n"NOR,
HIB"传承彼幽暗之力， \n"NOR,
HIB"赐予所能触及的一切， \n"NOR,
HIB"彼之判决！ \n"NOR,
        });


int spelling(object me,int n)
{
	if(environment(me)!=env)
	{
		me->delete_temp("in_deepblue");
		return 0;
	}
	if(n<sizeof(spelling_msg))
	{
		message_vision(spelling_msg[n],me);
		call_out("spelling",1,me,n+1);
	}
	else
		begin_perform(me);
	return 1;
}

int main(object me)
{

	
	if(!objectp(env=environment(me)))
	{
		me->delete_temp("in_deepblue");
		return 0;
	}
	if(me->query_temp("in_deepblue"))
		return notify_fail("你正在使用“深蓝之判决”中。\n");
		
	message_vision(HIR"$N双眸微闭，两手快速地结著法印，神情专注，口中念道：\n"NOR,me);
	me->start_busy(10);
	me->set_temp("in_deepblue",1);
	call_out("spelling",1,me,0);
	

	return 1;
}
