// Silencer@fengyun workgroup	June.2005


#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, num, i, duration, title;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
	object soldier;
	int strategy,leadership;
	int timer;

	if( userp(me) ) {
		if( me->query("family/master_id")!="master yue" || me->query("class")!="official" ) {
			return notify_fail("只有岳飞的弟子才能使用『十面埋伏阵』。\n");
		}
	}
	skill = me->query_skill("strategy",1);
	if( me->query_skill("strategy",1) < 250 || me->query_skill("leadership",1) < 250 ) {
		return notify_fail("『十面埋伏阵』需要250级兵法和250级用人之技。\n");
	}
	if( me->query_temp("guard_count") < 2 ) {
		return notify_fail("你的护卫太少，列不出阵法耶。\n");
	}
	timer = 900;
	duration = me->query("timer/pfm/yue-shi") - time() + timer;
	if( duration > 0 ) {
		return notify_fail("你还需要等待"+(int)(duration/60)+"分钟左右才能再次发动十面埋伏之阵。\n");
	}
	if( !me->is_fighting() ) {
		return notify_fail("十面埋伏阵只能在战斗中发动！\n");
	}
	if( me->query_temp("max_guard") > 1 ) {
		return notify_fail("十面埋伏之阵正在发动！\n");
	}
	if( (int)me->query("force") < 200 ) {
		return notify_fail("『十面埋伏阵』需要耗费200点的内力。\n");
	}
	if( userp(me) ) {
		me->add("force", -200);
	}
	me->set("timer/pfm/yue-shi",time());
	msg = BGRN + HIY "$N"BGRN + HIY "挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"十面埋伏之阵！\n" NOR HIW"
滚滚烟云中，两名将官白衣白袍，如神兵天降，冲杀过来！\n\n"NOR; 	
	message_vision(msg, me);
	seteuid(getuid());
	soldier = new("/obj/npc/spirit_guard");
	soldier->set("no_purge", 1);
	soldier->move(environment(me));
	soldier->invocation(me, (skill+ me->query_skill("leadership",1)));
	if( soldier ) {
		message_vision(WHT"$N高喝：贼子休走，吃俺岳云一枪！\n"NOR, soldier);
	}
	soldier->set("no_purge", 0);
	soldier = new("/obj/npc/spirit_guard");
	soldier->set("no_purge", 1);
	soldier->set("name","张宪");
	soldier->move(environment(me));
	soldier->invocation(me, (skill+ me->query_skill("leadership",1)));
	if( soldier ) {
		message_vision(WHT"$N高喝：贼子休走，吃俺张宪一枪！\n"NOR, soldier);
	}
	soldier->set("no_purge", 0);
	return 1;
}