// neon@fengyun.com

#include <ansi.h>
#include <combat.h>
inherit ITEM;

void generate_name();

void create()
{	generate_name();
	set_weight(10);
	set("unit", "条");
    	set("long", "一条如灵蛇般的锁链（shootc）。\n");
	set("value", 0);
	set("level", 50);
	set("no_drop",1);
	set("no_burn",1);
	::init_item();
}

void init(){
	add_action("do_shoot", "shootc");
	add_action("do_shoot", "shoot");
}

int do_shoot(string arg){
	object me, target;
	int level, mod;
	string msg;
	
	me = this_player();
	if (!arg) return notify_fail("你要对谁使用法器？\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	target = present(arg,environment(me));
	
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) ) 
		return notify_fail( this_object()->name() + "只能对战斗中的对手使用。\n");	
	
	if (target->is_busy())
		return notify_fail("对方已经手忙脚乱了。\n");
	
	level = (int) query("level");
   	   
	msg  = query("color") + "\n$N念动真言，祭起一" + query("unit") + name() +"，";
	msg += query("color") + "\n\n蒙蒙云气卷地而起，腾入空中。\n云霓流动不息，忽然凝聚如游龙从空中飞下向$n卷来！！\n\n"NOR;
	
	mod = COMBAT_D->can_busy(me, target, "alchemy");	
	if (!mod)	mod = 10000;
	if (COMBAT_D->do_busy_attack(me, target,"chain", "step", 200, mod))
	{
		msg +=  query("color") + "层层叠叠的云气缠结在$n周围，$n一阵手忙脚乱！\n" NOR;
		target->force_busy(4);
		target->set_temp("busy_timer/chain",time());
		message_vision(msg, me, target);
	} else
	{
		msg += YEL"但是被$n机灵地躲开了。\n"NOR;
		message_vision(msg, me, target);
	}
	
   	me->start_busy(2);
	destruct(this_object());
	return 1;
}

void generate_name(){
	string *color = ({YEL, WHT, MAG});
	string *action = ({"缚", "捆", "绊","擒"});
	string *kind = ({"神索", "仙绳","妖练"});
	string m_color =(color[random(sizeof(color))]);
	set_name( m_color +(action[random(sizeof(action))]) 
		   + (kind[random(sizeof(kind))])
		   + NOR, ({ "lian" , "chain"}) );
	set("color", m_color);
	
}
