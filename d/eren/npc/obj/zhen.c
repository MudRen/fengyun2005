#include <ansi.h>
#include <combat.h>
inherit ITEM;

void create()
{	set_name( WHT"冰魄神针"NOR, ({ "shen zhen" , "zhen"}) );
	set_weight(10);
	set("unit", "根");
    set("long", "一根晶莹的银针，据说在千年冰蟾的血里浸泡过，中者骨酥筋软，在三轮内不能动弹，自我忙乱一轮，至少需要五十级无有之术。注意，此暗器连续使用效果不佳。\n");
	set("desc_ext", "shootz 某人");
	set("value", 7000);
	set("level", 50);
	::init_item();
}

void init(){
	add_action("do_shoot", "shootz");
}

int do_shoot(string arg){
	object me, target;
	int mod, level;
	string msg;
	 
	
	me = this_player();
	
	if (!arg) return notify_fail("你要对谁使用暗器？\n");
	
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	target = present(arg,environment(me));
		
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) ) 
		return notify_fail( this_object()->name() + "只能对战斗中的对手使用。\n");	
	if (target->is_busy())
		return notify_fail("对方已经不能动弹了。\n");
	
	level = me->query_skill("theorem",1);
	if (level< query("level")){
		tell_object(me,"你需要"+ query("level")+"的无有之术才能使用此暗器。\n");
		return 1;
	}
	
	msg  = WHT"\n$N将手一挥，"NOR +name()+WHT"无声无息地从衣袖中飞出。\n\n"NOR;
	
	mod = COMBAT_D->can_busy(me, target, "meihua-biao");	
	if (!mod) mod = 10000;
	
	if (COMBAT_D->do_busy_attack( me, target, "du-anqi","step",300, mod)) {
		msg +=  HIM + "$n浑身一麻，动弹不得！\n" NOR;
			target->force_busy(3);
	} else
		msg += YEL"但是被$n机灵地躲开了。\n"NOR;
	
	target->set_temp("busy_timer/meihua-biao",time());
	message_vision(msg, me, target);
	me->perform_busy(1);
	destruct(this_object());
	return 1;
}
