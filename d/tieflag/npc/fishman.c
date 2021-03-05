#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("渔夫", ({ "fishman" }) );
        set("gender", "男性");
        set("age", 52);
		set("long",
		"这是一个满脸风霜的老渔夫。\n");
		set("combat_exp", 5000);
		set("attitude", "friendly");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

