// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("石敢当", ({ "shi gandang","shi","gandang" }) );
        set("title",YEL"金狮镳局"NOR);
		set("nickname",CYN"敢做敢当"NOR);
        set("gender", "男性" );

		set("age",47);

	set("chat_chance",2);
	set("chat_msg", ({
		"石敢当竭力向山上爬去，满头大汗。\n",
		"石敢当擦了擦汗，叹道：这劳什子山，没事长这么高干啥。\n",
	}) );

        set("combat_exp", 5600000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(70) :),
        }) );

		setup();

        weapon=carry_object("/obj/weapon/hammer");
        weapon->set_name(YEL"敢当锤"NOR, ({ "hammer" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("青色镳衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",220,200,0,"/obj/weapon/","fighter_w","pangu-hammer",1);
}
