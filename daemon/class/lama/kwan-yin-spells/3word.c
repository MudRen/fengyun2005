//mimicat@fy4

#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{	
	int extra, mana, manaexpend;
	string *word,arg;
	int b1, b2, i;

	if( me->query("class") != "lama" ) {
		return notify_fail("只有大昭寺的弟子才能使用观音六字明咒。\n");
	}
	extra = me->query_skill("kwan-yin-spells", 1);
	if( extra < 200 ) {
		return notify_fail("『三字真言』需要200级的观音六字明咒。\n");
	}
	word = allocate(3);
	arg = me->query("marks/pfm/3word");

	if( !target ) {
		target = offensive_target(me);
	}
	if( !target) {
		target = me;
	}
	if( !arg ) {
		return notify_fail("三字真言必须先做准备。\n");
	}
	if( sscanf(arg, "%s+%s+%s", word[0], word[1], word[2]) != 3 ) {
		return notify_fail("你的三字真言没准备好。\n");
	}
	
	manaexpend=450;
	
	if (ANNIE_D->check_buff(me, "feat"))
		manaexpend=manaexpend/2;
	
	mana = me->query("mana");
	if(mana < manaexpend ) {
		return notify_fail("三字真言至少需要"+manaexpend+"点法力。\n");
	}
	b1 = 0;
	b2 = 0;
	for( i = 0; i < 3; i++ ) {
		if( objectp(me) && objectp(target) && living(me) && !me->query_temp("is_unconcious") && environment(me) == environment(target) ) {
			b1 = me->query_busy();
			b2 = b2 + b1;
			me->stop_busy();
			SKILL_D("kwan-yin-spells")->cast_spell(me, word[i], target);
		} else {
			if( me->query("mana") < mana-manaexpend ) {
				if( userp(me) ) {
					me->set("mana", mana-manaexpend);
				}
			}
			b1 = me->query_busy();
			b2 = b2 + b1;
//			write (" b2 = " + b2 +"\n");
			if( b2 > 6 ) {
				b2 = 6;
			}
			me->start_busy(b2);
//			write (" b2 = " + b2 +"\n");
			tell_object(me, YEL"你的三字真言不满足继续的条件！\n"NOR);
			return 1;
		}
	}

	if( me->query("mana") < mana-manaexpend ) {
		if( userp(me) ) {
			me->set("mana", mana-manaexpend);
		}
	}

	b1 = me->query_busy();
	b2 = b2 + b1;
//	write (" b2 = " + b2 +"\n");
	if( b2 > 6 ) {
		b2 = 6;
	}
//	write (" b2 = " + b2 +"\n");
	me->start_busy(b2);
	return 1;
}
