#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("茅大先生", ({ "mr da" }) );
        set("gender", "男性");
	set("age",75);
        set("combat_exp", 1000000);
        set("long",
		"一个白发苍苍的老人而已，没有什么特别的地方。\n"
	);
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(80) :),
        }) );
    	    	
    	auto_npc_setup("wang",150,160,1,"/obj/weapon/","fighter_w","feixian-sword",1);
        setup();
	carry_object("/obj/armor/cloth")->wear();
}
