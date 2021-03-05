// neon@fengyun.com

#include <ansi.h>
#include <combat.h>
inherit ITEM;

void create()
{	set_name( WHT"落云锥"NOR, ({ "luoyun zhui" , "zhui"}) );
	set_weight(10);
	set("unit", "柄");
    	set("long", "一柄晶晶闪亮的飞锥，可以用来射人（shootz）。\n");
	set("value", 0);
	set("level", 50);
	set("no_drop", 1);
	set("no_burn",1);
	::init_item();
}

void init(){
	add_action("do_shoot", "shootz");
	add_action("do_shoot", "shoot");
}

int do_shoot(string arg){
	object me, target;
	int level, damage, exp_bonus;
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
	
	level = (int) query("level");
   	damage = 0;
   
	msg  = HIW"$N念动真言，指并剑诀，祭起一" + query("unit") + name()+HIW"，";
	msg += HIW"\n只见一道白光急射$n！！\n\n"NOR;

//	 success rate:1/2+ random(5)
//	damage = 200*100/10= 2000, 2000+random(2000); at 8M 3000+random(3000);
//	/3
	if (COMBAT_D->do_magic_attack( me, target, "magic", "sen", 50)) {
		msg +=  name() +HIW "象一道闪电击中了$n！！\n" NOR;
		damage = me->query_skill("alchemy",1)* level /30;
		damage = damage + random(damage);
		if (userp(me)) exp_bonus= (me->query("combat_exp")-4000000)/1000*damage/8000;
		damage = damage + exp_bonus;
		if (damage>6000) damage = 6000;
		damage = COMBAT_D->magic_modifier(me, target, "kee", damage/3);
		target->receive_wound("kee",damage,me);
		target->set_temp("damaged_during_attack", 2);
           	message_vision(msg, me, target);
           	COMBAT_D->report_status(target);
           	COMBAT_D->win_lose_check(me,target,1);
           	
	} else
	{
		msg += YEL"但是被$n机灵地躲开了。\n"NOR;
		message_vision(msg, me, target);
	}
   	me->start_busy(2);
	destruct(this_object());
	return 1;
}

