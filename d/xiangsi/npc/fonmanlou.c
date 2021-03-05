// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("风满楼", ({ "feng manlou","feng","manlou" }) );
        set("title",HIG"风家大少"NOR);
		set("nickname",HIM"深信自己是一种最伟大、最光荣的存在"NOR);
        set("gender", "男性" );

		set("age",25);
        set("long",HIR"一个胖乎乎的人，看起来该减肥了。\n"NOR);

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
        }) );

        set("combat_exp", 7000000);
        set("score", 50);
		set("chat_chance", 100);
		set("chat_msg", ({
		(: leave :),
		}) );

		set("death_msg",CYN"\n$N叹道：出来混，迟早是要还的．．．\n"NOR);

		setup();

		auto_npc_setup("fon manlou",200,220,0,"/obj/weapon/","fighter_w","longfenghuan",1);

        weapon=carry_object("/d/chuenyu/npc/obj/pigmeat");
        weapon->set_name(YEL"五花大肥肉"NOR, ({ "meat","fat" }) );
		weapon->set("long","这简直就只是一块油脂。\n");
		weapon->delete("wield_msg");
		weapon->set("base_unit","块");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("特意裁大的衣物", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

void rob(object who)
{
	object me = this_object();
	message_vision(CYN"\n$N脸上横肉颤动，对$n道：小兔崽子，乖乖的把钱交出来！\n\n"NOR,me,who);
	me->kill_ob(who);
}

int accept_object(object who, object ob)
{
	object me = this_object();
	if (ob->query("value") >= 50000)
	{
		message_vision(CYN"\n$N哼了一声，满足的拍拍肚皮。\n"NOR,me,who);
		message_vision(CYN"$N慢慢的走回山石之后。\n\n"NOR,me,who);
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
	message_vision(CYN"$N摇摇头，慢慢的走回山石之后。\n"NOR,me);
	destruct(this_object());
}

void killed_enemy(object who)
{
	remove_killer(who);
	who->remove_killer(this_object());
	if (!is_fighting())
		stop_busy();
}
