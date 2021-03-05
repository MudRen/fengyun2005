// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
int leave();

void create()
{
	object weapon;
        set_name("土强盗", ({ "naked bandit","bandit" }) );
        set("title",CYN"赤身裸体"NOR);  
        set("gender", "男性" );

        set("long","一个身上挂着几根破草，衣不蔽体的土强盗。\n");

        set("combat_exp", 200000);
        set("score", 50);
		set("skill_public",1);
        set_skill("throwing", 100);
        set_skill("dodge", 100);

		set("chat_chance", 100);
		set("chat_msg", ({
		(: leave :),
		}) );

        set_skill("meihua-biao", 10);
        set_skill("13-sword", 10);

        map_skill("throwing", "meihua-biao");
        map_skill("dodge", "13-sword");

		set("death_msg",CYN"\n$N叫道：我．．我只是．．．只是想有件衣服穿啊．．．．．\n"NOR);

		setup();

        weapon=carry_object(__DIR__"obj/stone");
        weapon->set_name("石块", ({ "stone" }) );
		weapon->set("long","一堆小石子。\n");
		weapon->set("base_unit","块");
		weapon->set("value",0);
		weapon->set_amount(10);
		weapon->set("volumn",10);
		weapon->wield();

}

void rob(object who)
{
	object me = this_object();
	if (!who->is_naked())
	{
		message_vision(CYN"\n$N大喝道：把．．把．．把衣服留下来！\n"NOR,me,who);
		me->kill_ob(who);
	}
	else
	{
		message_vision(CYN"\n$N上下打量了$n几眼，叹道：原来也是个穷人。\n"NOR,me,who);
		message_vision(CYN"$N摇摇头，跳回山石后面不见了。\n"NOR,me,who);
		destruct(this_object());
	}
}

int accept_object(object who, object ob)
{
	object me = this_object();
	if (ob->query("armor_prop") || ob->query("value") >= 10000)
	{
		message_vision(CYN"$N张大嘴巴，看着"+ob->name()+CYN"啊，啊的发了几声。\n"NOR,me,who);
		message_vision(CYN"$N欢天喜地的捧着"+ob->name()+CYN"跑走了。\n"NOR,me,who);
		remove_all_killer();
		move(load_object("/obj/void"));
		return 1;
	}
	return 0;
}

int leave()
{
	object me = this_object();
	command("get all from corpse");
	message_vision(CYN"$N摇摇头，垂头丧气的转回山石之后。\n"NOR,me);
	destruct(this_object());
}

void killed_enemy(object who)
{
	remove_killer(who);
	who->remove_killer(this_object());
	if (!is_fighting())
		stop_busy();
}
