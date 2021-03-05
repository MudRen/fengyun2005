#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg;
	int lvl;
	object corp, room, ghost;

	if( me->query("class") != "yinshi" ) {
		return notify_fail("只有帝王谷弟子才能下降头。\n");
	}
	if( (int)me->query_skill("celecurse",1) < 100 ) {
		return notify_fail("尸降需要100级的通天降！\n");
	}
	if( !target || !target->is_ghost() || userp(target) ) {
		return notify_fail("你只能对鬼魂下这个降头。\n");
	}
	room = environment(target);
	if( me->query_temp("timer/solidghost") > 0 ) {
		return notify_fail("你已经控制住一个亡灵了。\n");
	}
	if( !corp = present("corpse",environment(me)) ) {
		return notify_fail("你的周围没有尸体！\n");
	}
	if( (int)me->query("kee") < 100 ) {
		return notify_fail("需要１００点气血！\n");
	}
	me->receive_wound("kee", 100);
	lvl=me->query_skill("cursism");
	msg = HIC "$N凌空对着$n虚点几下，$n缓缓的站了起来！\n\n" NOR;
	message_vision(msg,me,corp);
	seteuid(getuid());
	ghost = new("/obj/npc/solidghost");
	if( ghost ) {
		ghost->set("no_purge", 1);
		ghost->set("name", corp->query("victim_name")+"的亡灵");
		ghost->set("gender", corp->query("gender"));
		ghost->move(environment());
		ghost->invocation(me, lvl); // maximum enable lvl = 200x２ + 200*0.5 = 500
		destruct(target);
		destruct(corp);
		me->set_temp("timer/solidghost",1);
		msg = HIC "$n对$N发出了令人毛骨悚然的笑声：“主人，有什么吩咐。。。”\n\n" NOR;
		message_vision(msg, me, ghost);
		ghost->set("no_purge", 0);
		me->perform_busy(2);
	}
	return 1;
}

