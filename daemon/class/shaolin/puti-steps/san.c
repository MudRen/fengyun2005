// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, num, i, duration, add;
	object* shiwei;
	mapping buff;
	string msg;
	int extra, maximum, gcount, count;
	object recruit;
	object* enemy;

	if( userp(me) ) {
		if( me->query("family/master_id") != "master yue" || me->query("class") != "official" ) {
			return notify_fail("只有岳飞的弟子才能使用『三才天地人阵』。\n");
		}
	}
	skill = me->query_skill("strategy",1);
	if( me->query_skill("strategy",1) < 160 || me->query_skill("leadership",1) < 160 ) {
		return notify_fail("『三才天地人阵』需要160级兵法和160级用人之技。\n");
	}
	add = F_ABILITY->check_ability(me,"3_array_add",3)*4/10;
	duration = me->query("timer/pfm/yue_array") - time() + 10 - add;
	if( duration > 0 ) {
		return notify_fail("你需要等待片刻（"+ duration +"秒）才能再次变幻阵法。\n");
	}
	maximum = 2;
	if( me->query_skill("leadership",1) >= 250 ) {
		maximum = 4;
	} else if( me->query_skill("leadership",1) >= 175) {
		maximum = 3;
	}
	gcount = me->query_temp("guard_count");
	if( gcount >= maximum ) {
		return notify_fail("你现在不需要列三才天地人阵。\n",me);
	}
	if( userp(me) && me->is_fighting() ) {
		return notify_fail("该阵法在战斗中使用没有效果的。\n");
	}
	duration = me->query_temp("timer/pfm/gf_san") - time() + 120;
	if( userp(me) ) {
		if( duration > 0 ) {
			return notify_fail("『三才天地人阵』每两分钟只能排练一次。\n");
		}
	}
	if( (int)me->query("force") < 200 ) {
		return notify_fail("『三才天地人阵』需要耗费200点的内力。\n");
	}
	if( userp(me) ) {
		me->add("force", -200);
	}
	msg = BGRN + HIY "$N"BGRN + HIY "挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"三才天地人之阵！\n" NOR;
	message_vision(msg, me);
	msg = YEL"忽见阵外腾腾腾走来一名壮士，扑地拜倒在$N"NOR+YEL"身前，朗声说道：将军之义，天高水长，\n在下$n愿在帐前效力，卫国杀敌，万死不辞。\n\n"NOR;
	extra=me->query_skill("strategy",1)+ me->query_skill("leadership",1);
	seteuid(getuid());
	me->set("timer/pfm/yue_array",time());
	me->set_temp("timer/pfm/gf_san",time());
	while( me->query_temp("guard_count") < maximum ) {
		if( userp(me) ) {
			recruit=new("/obj/npc/huwei");
		} else {
			recruit=new("/obj/npc/spirit_guard"); // so they can disappear after fight
		}
		recruit->set("no_purge", 1);
		recruit->move(environment(me));
		recruit->invocation(me,extra);
		message_vision(msg, me, recruit);
		me->add_temp("guard_count",1);
		if( !userp(me) ) {
			enemy = me->query_enemy();
			i = sizeof(enemy);
			while( i-- ) {
				if( enemy[i] && living(enemy[i]) ) {
					recruit->kill_ob(enemy[i]);
					if( userp(enemy[i]) ) {
						enemy[i]->fight_ob(shiwei);
					} else {
						enemy[i]->kill_ob(recruit);
					}
				}
			}
		}
		recruit->set("no_purge", 0);
	}
	return 1;
}
