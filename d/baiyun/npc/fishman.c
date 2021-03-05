#include <ansi.h>
inherit NPC;  
void create()
{
	set_name("渔夫", ({ "fishman" }) );
	set("gender", "男性");
	set("age", 45);
	set("long","这是一个满脸风霜的渔夫。\n");
    set("combat_exp", 10000);
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

