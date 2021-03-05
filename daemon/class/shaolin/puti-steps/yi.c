// Silencer@fengyun workgroup	June.2005


#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, num, i, duration, title, hate;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
	object soldier, *enemy;
	int strategy, leadership;
	int timer;
	if( userp(me) ) {
		if( me->query("family/master_id") != "master yue" || me->query("class") != "official" ) {
			return notify_fail("只有岳飞的弟子才能使用『一字长蛇阵』。\n");
		}
	}
	skill = me->query_skill("strategy",1);
	if( me->query_skill("strategy",1) < 100 || me->query_skill("leadership",1) < 100 ) {
		return notify_fail("『一字长蛇阵』需要100级兵法和100级用人之技。\n");
	}
	timer = 1800 - F_ABILITY->check_ability(me,"yi_add")*60;
	duration = me->query("timer/pfm/alert") - time() + timer;
	if( duration > 0 ) {
		return notify_fail("你还需要等待"+(int)(duration/60)+"分钟左右才能再次发动一字长蛇阵。\n");
	}
	if( ANNIE_D->check_buff(me,"lockfield") >= 1 ) {
		return notify_fail("此地地势不利，无法发动一字长蛇阵。\n");
	}
	if( !me->is_fighting() ) {
			return notify_fail("一字长蛇阵只能在战斗中发动！\n");
	}
	if( me->query_temp("max_guard") > 1 ) {
		return notify_fail("一字长蛇阵正在发动！\n");
	}
	msg = BGRN + HIY "$N挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"一字长蛇之阵！\n" NOR HIB"
滚滚烟云中，一人黑衣、黑马、黑旗，卷至$N身前叫道：阵法已动，将军速退，待末将断后！\n\n"NOR;

	message_vision(msg, me);
	me->set("timer/pfm/yue_array",time());
	seteuid(getuid());
	soldier = new("/obj/npc/danei_guard");
	if( soldier ) {
		soldier->set("no_purge", 1);
		soldier->move(environment(me));
		soldier->invocation(me, (skill+ me->query_skill("leadership",1)));
		soldier->set_name(WHT"死士"NOR,({ "sishi" })); 
		enemy = me->query_enemy();
		if( enemy ) {
			for( i = 0; i < sizeof(enemy); i++ ) {
				hate = enemy[i]->query_hate(me);
				enemy[i]->add_hate(soldier, hate);
			}
			me->remove_all_killer();
			me->add_temp("max_guard",1);
		}
		me -> set("timer/pfm/alert",time());
		soldier->set("no_purge", 0);
	}
	return 1;
}