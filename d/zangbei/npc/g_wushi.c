inherit SMART_NPC;
#include <ansi.h>

void create()
{
	set_name("执戈武士", ({ "soldier"}) );
	set("title","龟兹国");
	set("gender", "男性" );
	set("age", 30+random(20));
	set("long","执戈肃立的武士，凶神恶煞一般，高额凹眼，不似中原人氏。\n");
	set("attitude", "friendly");
	set("combat_exp", 2500000);
	
        set("attitude", "friendly");
        set("class","fugui");
        set("group_1","guizi");
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(40) :),
     	}) );
        
		auto_npc_setup("wang",160,200,0,"/obj/weapon/","fighter_w","xuezhan-spear2",1);
		setup();
		carry_object(__DIR__"obj/g_armor")->wear();
        carry_object(__DIR__"obj/g_spear")->wield();
}
