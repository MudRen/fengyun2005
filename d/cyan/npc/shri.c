// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("席若音", ({ "xi ruoyin","xi","ruoyin" }) );
        set("title","明霞山 "HIB"奉剑"NOR);
		set("nickname",HIG"风吹落花"NOR);
        set("gender", "男性" );
		set("class","moon");

		set("age",21);

        set("long","席若音盘腿坐在瞭望台边，静静地看着风云翻卷。\n");

	set("chat_chance",2);
	set("chat_msg", ({
		"席若音微微一笑，低声道：那我对你这么好，又是为什么？\n",
		"席若音慢慢呼出了一口悠长悠长的气息。\n",
		"席若音探出头，向古瞭望台下望去，不知在想些什么。\n",
	}) );

        set("combat_exp", 6700000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
             }) );


		set("death_msg",CYN"\n$N幽幽叹了口气：我活著，原本也没什么意义．．．\n"NOR);

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("霜冷剑", ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/weapon/dagger");
        weapon->set_name("短树枝", ({ "dagger" }) );
		weapon->set("value",0);

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("青衫", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",220,200,0,"/obj/weapon/","fighter_w","tempestsword",4);
}
