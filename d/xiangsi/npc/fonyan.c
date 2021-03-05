// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
int leave();

void create()
{
	object weapon;
        set_name("风颜", ({ "feng yan","feng","yan" }) );
        set("title",HIG"风家二少"NOR);
		set("nickname",WHT"灌溉满菁华 诗人读憔悴"NOR);
        set("gender", "男性" );

		set("age",22);

        set("long","一个手持白纸扇，风度翩翩的少年公子。\n");

        set("combat_exp", 1000000);
        set("score", 50);
		set("chat_chance", 100);
		set("chat_msg", ({
		(: leave :),
		}) );

        set_skill("dagger", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("liuyun-dagger", 90);
        set_skill("13-sword", 90);
		set_skill("unarmed",600);	// dont knock down my weapon

        map_skill("dagger", "liuyun-dagger");
        map_skill("parry", "liuyun-dagger");
        map_skill("dodge", "13-sword");

		set("death_msg",CYN"\n$N叫道：本公子．．．做鬼也不饶你！\n"NOR);

		setup();

        weapon=carry_object("/d/qianjin/npc/obj/zheshan");
        weapon->set_name(WHT"白纸扇"NOR, ({ "shan zi","shan" }) );
		weapon->set("base_unit","块");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("文士长衫", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

void rob(object who)
{
	object me = this_object();
	message_vision(CYN"\n$N温文儒雅的一躬，对$n道：请多指教。\n\n"NOR,me,who);
	me->kill_ob(who);
}

int accept_object(object who, object ob)
{
	object me = this_object();
	if (ob->query("value") >= 30000)
	{
		message_vision(CYN"\n$N微微一笑，说道：小弟却之不恭，就不客气了。\n"NOR,me,who);
		message_vision(CYN"$N慢慢的踱回山石之后。\n\n"NOR,me,who);
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
	message_vision(CYN"$N摇摇头，慢慢的踱回山石之后。\n"NOR,me);
	destruct(this_object());
}

void killed_enemy(object who)
{
	remove_killer(who);
	who->remove_killer(this_object());
	if (!is_fighting())
		stop_busy();
}
