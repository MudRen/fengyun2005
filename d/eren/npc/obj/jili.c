// neon@fengyun.com

#include <ansi.h>
#include <combat.h>
inherit ITEM;

void generate_name();

void create()
{	set_name( HIB"毒蒺藜"NOR, ({ "du jili" , "jili"}) );
	set_weight(10);
	set("unit", "颗");
    set("long", "一颗淬满了剧毒的暗器，伤人心神为无有之术等级乘三，至少需五十级无有之术。\n");
    set("desc_ext", "shootd 某人");
	set("value", 8000);
	set("level", 50);
	::init_item();
}

void init(){
	add_action("do_shoot", "shootd");
}


int do_shoot(string arg){
	object me, target;
	int level, exp, t_exp, damage, exp_bonus, resist;
	string msg;
	
	me = this_player();
	if (!arg) return notify_fail("你要打谁？\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	target = present(arg,environment(me));
	
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) ) 
		return notify_fail( this_object()->name() + "只能对战斗中的对手使用。\n");	
	
	level = me->query_skill("theorem",1);
	if (level< query("level")){
		tell_object(me,"你需要"+ query("level")+"的无有之术才能使用此暗器。\n");
		return 1;
	}
	
   	damage = 0;
   
	t_exp = (int) target->query("combat_exp");
	exp   = (int) me->query("combat_exp");
	msg  = HIB"$N中指一弹，扣在手心的毒蒺藜激射而出！！\n\n"NOR;
	if( random(exp*5) + exp/2 > t_exp ) {
		damage = level*3;
		damage = COMBAT_D->magic_modifier( me, target, "sen", damage);
		msg +=  HIM"$n闪避不及，被毒蒺藜打中肩头，顿时一阵头昏眼花。\n" NOR;
		target->receive_damage("sen",damage,me);
		target->receive_wound("sen",damage,me);
	} else
		msg += YEL"但是被$n机灵地躲开了。\n"NOR;

	message_vision(msg, me, target);
	if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
    }
   	me->perform_busy(2);
	destruct(this_object());
	return 1;
}
