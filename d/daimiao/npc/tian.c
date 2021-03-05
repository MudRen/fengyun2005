inherit SMART_NPC;
#include <ansi.h>

void create()
{
    	set_name("天时老人", ({ "master tian", "tian","master"}) );
    	set("nickname", HIW "天舵舵主"NOR);
    	set("title","西方神教");
    	set("gender", "男性" );
    	set("reward_npc", 1);
		set("difficulty", 5);
    	set("group", "demon");
        set("vendetta_mark","demon");
    	set("age", 64);
    	set("per", 3);
    
    	set("attitude","friendly");
    	   	
    	set("long", "天时老人在西方神教中的地位是数一数二的，\n统领着西方神教中的天舵。\n");
    	
    	set("combat_exp", 8500000);
    	set("score", 200000);
    	
    	set("smartnpc_busy",1);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
        }) );
        
    	auto_npc_setup("wang",200,300,0,"/obj/weapon/","fighter_w","demon-strike",2);
    	setup();
    	carry_object(__DIR__"obj/duoyi")->wear();
}
