inherit SMART_NPC;
#include <ansi.h>

void create()
{
    	set_name("人和老人", ({ "master ren", "ren","master"}) );
    	set("nickname", HIW "人舵舵主"NOR);
    	set("title","西方神教");
    	set("gender", "男性" );
    	set("group", "demon");
        set("vendetta_mark","demon");
    	set("reward_npc", 1);
		set("difficulty", 2);
    	set("age", 62);
    	set("per", 3);
    
    	set("attitude","friendly");
    
    	set("long", "人和老人在西方神教中的地位是仅次于地利老人的，\n"
        	    "人和老人统领着西方神教中的人舵。\n");
    
   		set("combat_exp", 7300000);
    	set("score", 200000);
    	set("smartnpc_busy",1);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
        
    	auto_npc_setup("wang",200,250,0,"/obj/weapon/","fighter_w","demon-strike",2);
    	setup();
    	carry_object(__DIR__"obj/duoyi3")->wear();

}
