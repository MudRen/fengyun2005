#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("钦卫", ({ "imperial guard", "guard" }) );
        set("long",
                "一群如狼似虎的钦点护卫。\n");
	set("cor",20);
        set("attitude", "heroism");
        set("combat_exp", 1500000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
		"钦卫号道：风平．．．．．浪静．．．．．．\n"
        }) );

	auto_npc_setup("wang",180,140,0,"/obj/weapon/","fighter_w","taiji",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

