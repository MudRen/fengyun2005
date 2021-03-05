// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int look_stone();


void smart_fight()
{
	string msg;
	object t = select_opponent();
	object me=this_object();
	int i;

	if (is_busy())
		return;

	if (!query("enemy") || environment(query("enemy")) != environment())
		set("enemy",t);
	
	t=query("enemy");

	i=query("pfm");
	i++;
	if (i>=5)
		i=1;
	
	set("pfm",i);

	switch (i)
	{
	case 1:
		msg=YEL"\n$N"YEL"使出太极剑法中的流沙诀攻向$n"YEL"，剑势有如千里流沙般连绵不绝，暗含杀机！...\n"NOR;
		msg += WHT"结果$n"WHT"被$N"WHT"攻了个措手不及，动作迟滞，如陷沙积！\n\n" NOR;
		message_vision(msg,me,t);
		t->force_busy(3);
		perform_busy(1);
		break;
	case 2:
		message_vision(HIY"\n$N"HIY"趁$n"HIY"动作迟滞，手腕一振，"+me->query_temp("weapon")->name()+HIY"幻出万道剑环，虚虚实实，相连无缝，正是太极剑法中缠字诀变招「紫府云封」！\n"NOR,me,t);
		message_vision(HIC "$N"HIC"为$n"HIC"剑法所缠，封架不及，顿时破绽百出！\n\n"NOR,t,me);
		t->force_busy(3);
		perform_busy(1);
		break;
	case 3:
		msg = HIR "\n$N"HIR"抓住$n"HIR"破绽，弃剑换掌，真气鼓动，双拳幻化为无数大大小小的圆圈向$n"HIR"攻去，\n";
		msg += "	结果$p头晕目眩，被$P的拳势围住不能脱身，频频中招！\n\n" NOR;
		t->force_busy(3);
		me->perform_busy(random(2));
		t->receive_damage("kee",1800,me);
		message_vision(msg, me, t);
		COMBAT_D->report_status(t, 0);
		break;
	case 4:
			msg=YEL"\n$N"YEL"吐气开声，双拳一转，$n"YEL"跌跌撞撞地斜冲出去，连打了几个转儿。\n"HIC"
然而$n"HIC"脚步尚未停稳，一道辉煌绚丽的剑光已经闪起，转瞬间迫近眼前！\n"NOR;

	me->add_temp("apply/attack", 800);
	me->add_temp("apply/damage", 3210);
		COMBAT_D->do_attack(me,t, TYPE_PERFORM,msg);
	me->add_temp("apply/damage", -3210);
	me->add_temp("apply/attack", -800);
	perform_busy(2);
	delete("enemy");
	}
}

void create()
{
	object weapon;
	set_name("李青卓", ({ "li qingzhuo","li","qingzhuo","liqingzhuo" }) );
	set("class","wudang");
	set("gender", "男性" );
	set("age", 26);

	set("nickname",WHT"鸟寂林息"NOR);
	set("title","武当派 "CYN"二弟子"NOR);

	set("long","\n永远是一身乾乾净净的白衣，永远是一把杏黄流苏的轻剑，\n李青卓随随便便往那里一站，就是一柄刚刚出鞘的绝世利剑。\n\n");

	set("no_fly",1);
	set("no_arrest",1);

	set("attitude", "peaceful");

	set("inquiry",([
		"*": "action李青卓一言不发，转头就走。",
		]) );

	set("combat_exp", 4800000);

	set("always_duxin",1);

	set_skill("sword", 200);
	set_skill("lefthand-sword", 220);
	set_skill("taiji-sword", 220);
	set_skill("windsword", 220);
	map_skill("sword","taiji-sword");
	set_skill("move",400);
	set_skill("five-steps",220);
	map_skill("move","five-steps");

	set_skill("unarmed", 200);
	set_skill("luoriquan", 220);
	set_skill("taiji", 220);
	map_skill("unarmed","taiji");

	set("no_kill",1);
	set_skill("iron-cloth",300);
	set_skill("incarnation",400);
	map_skill("iron-cloth","incarnation");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight() :),
	}) );

	setup();



        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(WHT"青号"NOR, ({ "sword" }) );
		weapon->set("long"," ");
		weapon->set("no_drop",1);
		weapon->set("nodrop_weapon",1);

		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("一尘不染的白衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

