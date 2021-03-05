#include <ansi.h>
#include <combat.h>
inherit ITEM;

void create()
{	set_name( HIY"掌心雷"NOR, ({ "zhangxin lei" , "lei"}) );
	set_weight(10);
	set("unit", "颗");
    set("long", "一柄晶晶闪亮的圆形暗器，内藏火药，中者立炸，伤人气血为无有之术等级乘四，至少需五十级无有之术。\n");
    set("desc_ext", "shootl 某人");
	set("value", 5000);
	set("level", 50);
	::init_item();
}


void init(){
	add_action("do_shoot", "shootl");
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
	msg  = HIW"$N双掌缓缓在身前移动，目不转睛地盯着对手，忽然间，双掌移动越来越快，
似已化作了无数双。$N大喝一声，一道寒光，随声暴射而出。\n\n"NOR;
	if( random(exp*5) + exp/2 > t_exp ) {
		damage = level *4;
		damage = COMBAT_D->magic_modifier( me, target, "kee", damage);
		msg +=  name() +HIW "象一道闪电击中了$n！！\n" NOR;
		target->receive_damage("kee", damage, me);
		target->receive_wound("kee",damage,me);
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

