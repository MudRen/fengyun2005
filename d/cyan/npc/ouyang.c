// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("欧阳急", ({ "ouyang ji","ouyang","ji" }) );
        set("title",YEL"金狮镳局"NOR);
		set("nickname",HIC"惊雷鞭"NOR);
        set("gender", "男性" );

		set("age",47);

        set("long","这个人是金狮镳局的骄傲，一路天雷鞭法出神入化，绿林中无人能敌。\n");

	set("chat_chance",8);
	set("chat_msg", ({
		"欧阳急皱眉道：是什么样的手法才能像插豆腐一样用脆弱的竹子插进石壁？\n",
		"欧阳急皱眉道：那人把滑竿插在这里，到底有什么涵义？\n",
		"欧阳急闷哼一声，对你说：你可能将这滑竿拔出来？\n",
	}) );

        set("combat_exp", 5800000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );



		set("death_msg",CYN"\n$N大叫道：你～～～～～～～～！\n"NOR);

		setup();

        weapon=carry_object("/obj/weapon/whip");
        weapon->set_name(HIC"惊雷鞭"NOR, ({ "whip" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("赤色镳衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",220,200,0,"/obj/weapon/","fighter_w","thunderwhip",1);
}
