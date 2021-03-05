// annie 6.27.03
// purge pets.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int check_legit(object ob); 
int purgepets(object me, object obj);

int perform(object me, object target)
{
	int i,flag = 0;
	object env;
	object * inv;

	if( !me->is_fighting())
		return notify_fail("「鬼神破灭」只能对战斗中的对手使用。\n");

	if(me->query("timer/check_gspm") + 2 > time())	
		return 0;
	me->set("timer/check_gspm",time());

	env = environment(me);
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if (check_legit(inv[i])) continue;
		if (!COMBAT_D->legitimate_kill(me, inv[i])) continue;
		if (purgepets(me, inv[i]))
			flag ++;
	}
	return flag;
}



int purgepets(object me, object obj)
{
	int a=0;
		string *msg = ({
"虹儿","西湖小青","水姑娘","胖天使","江北无言","十方妖灵","小蝶仙","猫依",
});
// 明月清辉,云中雪浅..
	if (base_name(obj) == "/obj/npc/solidghost")		// 帝王谷 solidspirit
		a=1;
	if (base_name(obj) == "/obj/npc/wolf")				// 狼山 wolf
		a=2;
	if (base_name(obj) == "/obj/npc/danei")				// 朝廷 alert-guard
		a=3;
	if (base_name(obj) == "/obj/npc/danei_guard")		// 朝廷 alert-guard
		a=3;
	if (base_name(obj) == "/obj/npc/shiwei")			// 朝廷 yin shiwei
		a=4;
	if (base_name(obj) == "/obj/npc/fighter1")			// 朝廷 yue huwei
		a=5;
	if (base_name(obj) == "/obj/npc/huwei")				// 朝廷 yue huwei
		a=5;
	if (base_name(obj) == "/obj/npc/zombie")			// 三清 zombie
		a=6;
	if (base_name(obj) == "/obj/npc/hell_guard")		// 三清 hell guard
		a=7;
	if (base_name(obj) == "/obj/npc/devil_guard")		// 三清 heaven soldier
		a=7;
	if (base_name(obj) == "/obj/npc/taoist_guard")		// 三清 sq-taoist
		a=8;
	if (base_name(obj) == "/obj/npc/heaven_soldier")	// 三清 sq-taoist
		a=8;
	if (base_name(obj) == "/obj/npc/fire_crane")		// 白云 fire crane
		a=9;

	return a;
}

int check_legit(object ob) {
	object me, *team, owner;
	me=this_player();
	
	if (ob->is_corpse() || !ob->is_character() || ob==me) return 1;
	team=me->query_team();
	if (team) {
		if (member_array(ob,team)!=-1) return 1;
		if (owner=ob->query("possessed"))
		if (member_array(owner,team)!=-1) return 1;
	}
	return 0;
}
