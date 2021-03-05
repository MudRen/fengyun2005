
#include <ansi.h>

inherit SSERVER;
int bbqthem(object me, object obj);

int cast(object me, object target)
{
	int i;
	object env, *inv, *myteam;

	if( me->query("class") != "lama" ) {
		return notify_fail("只有大昭寺的弟子才可以使用观音六字明咒！\n");
	}
	if( (int)me->query_skill("kwan-yin-spells", 1) < 160) {
		return notify_fail("『吽』需要160级的观音六字明咒！\n");
	}
	if( !me->is_fighting() ) {
		return notify_fail("『吽』只能在战斗中使用。\n");
	}
	if( me->query("mana") < 300 ) {
		return notify_fail("『吽』需要300点法力！\n");
	}
	if( userp(me) ) {
		me->add("mana", -300);
	}

	message_vision("\n"BRED + HIW "$N"BRED+HIW"右手于胸前展成莲花之状，左手折腕向上势若莲台，沉于右手下，面容肃静念道：\n"NOR
			"       "+ BRED+ HIY" 『吽』！" + BRED + HIW" ．．．只见$N"BRED+HIW"双手一瞬间发出比太阳还要耀眼的光芒！！！\n" NOR, me);

	env = environment(me);
	inv = all_inventory(env);
	for( i = 0; i < sizeof(inv); i++) {
		if( inv[i] == me ) {
			continue;
		}
		if( inv[i]->is_corpse() ) {
			continue;
		}
		if( !inv[i]->is_character() ) {
			continue;
		}
		if( !me->is_fighting(inv[i]) ) {
			continue;
		}
		bbqthem(me, inv[i]);
	}
	me->perform_busy(2);
	return 1;
}

int bbqthem(object me, object obj) 
{
	int mod;

	mod = COMBAT_D->can_busy(me, obj, "kwan-yin-spells");   
	if( !mod ) {
		return 1;
	}
	if( !COMBAT_D->do_busy_attack(me, obj, "kwan-yin-spells/hong", "unarmed", 400, mod) ) {
		message_vision(YEL"$N"NOR+YEL"连忙转过头去，不看$n。\n"NOR, obj, me);
		return 1;
	}

	obj->set_temp("busy_timer/kwan-yin-spells", time());

	if( userp(obj) ) {
		tell_object(obj, HIW"你只觉得眼前白茫茫的一片，什么都看不到了。。。\n"NOR);
		obj->add_temp("block_msg/all", 1);
		obj->force_busy(3 + random(2));
		message_vision(CYN"$N痛苦地捂住眼睛，直在地上打滚。\n\n"NOR, obj);
		call_out("recover", 10, obj);
	} else {
		obj->force_busy(3);
		obj->add_hate(me, me->query_skill("spells")*2);
		message_vision(CYN"$N痛苦地捂住眼睛，直在地上打滚。\n\n"NOR,obj);
	}
	return 1;
}


int recover (object obj)
{
	if(obj->query_temp("block_msg/all") >= 1 ) {
		obj->add_temp("block_msg/all", -1);
	}
	tell_object(obj, HIG"慢慢慢慢的，你的眼睛开始可以分辨周围的事物了。\n" NOR);
	return 1;
}	

