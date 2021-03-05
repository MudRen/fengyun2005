#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("仇二先生", ({ "mr er" }) );
        set("gender", "男性");
	set("age",35);
	set("combat_exp", 900000);
        set("class","baiyun");
        set("long",
"道装玄冠，长身玉立，背负长剑，苍白的脸上眼角上挑，带着种说不出的傲气，
两条几乎连接在一起的浓眉间，又仿佛充满了仇恨。\n"
	);

        set("chat_chance", 1);
        set("chat_msg", ({
		(: random_move :),
        }) );
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(80) :),
        }) );
    	    	
    	auto_npc_setup("wang",150,150,1,"/obj/weapon/","fighter_w","feixian-sword",1);
        setup();
	carry_object("/obj/armor/cloth")->wear();
}
