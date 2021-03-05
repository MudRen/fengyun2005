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
	set("no_drop", 1);
	::init_item();
}

void init(){
	add_action("do_shoot", "shootc");
}

int do_shoot(string arg){
	object me, target;
	int level, exp, t_exp, damage;
	int busy_num;
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
	
	level = (int) query("level");
   	damage = 0;
   
	t_exp = (int) target->query("combat_exp");
	exp   = (int) me->query("combat_exp");
	msg  = query("color") + "\n$N念动真言，祭起一" + query("unit") + name();
	msg += query("color") + "\n\n蒙蒙云气卷地而起，腾入空中。\n云霓流动不息，忽然凝聚如游龙从空中飞下向$n卷来！！\n\n"NOR;
	//if( random(exp)/2 + exp/2 > t_exp ) {
	if( random(exp)*level/50 + 4*exp/5 > t_exp ) {
		damage = me->query_skill("alchemy",1)* level /10;
		damage = damage/2 + 2 * random(damage);
		msg +=  query("color") + "层层叠叠的云气缠结在$n周围，$n一阵手忙脚乱！\n" NOR;
		target->receive_wound("kee", damage/20, me);
		target->add("sen",-damage/5);
		target->add("eff_sen",-damage/5);
		target->receive_damage("sen", 1, me);
		if (target->query("no_busy")) {
			busy_num = target->query("no_busy");
			target->delete("no_busy");
			call_out ("busy_recover",12, busy_num, target);
		}

		target->start_busy(4);
	} else
		msg += "但是被$n躲开了。\n";

	message_vision(msg, me, target);
	if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
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

int busy_recover (int busy_num, object obj)
{
	obj->set("no_busy",busy_num);
	return 1;
}	