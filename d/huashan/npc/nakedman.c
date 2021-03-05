// hu.c

inherit NPC;
#include <ansi.h>
 
void create()
{
		set_name("裸体大男人", ({ "nakedman" }) );
		set("title",HIB "无拘无束"NOR);
		set("gender", "男性" );
		set("age", 35);
    	set("long","
阳光，照着他满脸青惨惨的胡茬子，也照着他脸上那懒洋洋的笑容，
一双又黑又亮的大眼睛, 他就是楚留香最好的朋友胡铁花，又名花疯子。
\n");
		set("combat_exp", 1000000);
		set("attitude", "friendly");
	
		set_skill("force", 150);
		set_skill("bibo-force", 150);
    	set_skill("unarmed", 120);
    	set_skill("dodge", 120);
    	set_skill("luoriquan", 120);
    	set_skill("move", 120);
    	set_skill("fengyu-piaoxiang", 200);
    	set_skill("parry", 120);
    	
    	map_skill("force"  , "bibo-force");
    	map_skill("unarmed", "luoriquan");
    	map_skill("dodge"  , "fengyu-piaoxiang");
		map_skill("move"  , "fengyu-piaoxiang");
	
		set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        (: perform_action, "dodge.zonghengsihai" :),
            }) );
	
		setup();
}
