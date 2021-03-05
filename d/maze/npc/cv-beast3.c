#include <ansi.h>
inherit MAZE_NPC;


void create()
{
        set_name("魑", ({ "devil" }) );
        set("race", "野兽");
        set("class","taoist");
        set("maze","cave");
        set("age", 3);
        set("long", "这是一只由修道人的杂念绮思所化的观想兽，会缠住人的魂魄。\n"); 
        set("target_name","观想兽");
        set("combat_exp",1800000);
		set("attitude","aggressive");
		        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	
    	auto_npc_setup("wang",180,130,0,"/obj/weapon/","fighter_w","necromancy",1);
	
        setup();
}

