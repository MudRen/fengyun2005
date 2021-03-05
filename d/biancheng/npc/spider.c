#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("飞天蜘蛛",({"feitian zhizhu","feitian","zhizhu" }));
    	set("long","这人身手之快，做事之周到，当真不愧‘细若游丝，快如闪电’
这八个字。\n");
     	set("gender","男性");
    	set("age",32);
    	 	
    	set("combat_exp",5200000);  
    	set("attitude", "friendly");
    	    	
    	set("reward_npc",1);
    	set("difficulty",3);
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(90) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"飞天蜘蛛道：“在下一时游戏，千万恕罪。”\n"
    	}) );    	    	
    	    	
	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","fy-sword",1);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "短打劲装",
    						"long": "一件短打劲装。\n",
    						 ]))->wear();     
    
}
