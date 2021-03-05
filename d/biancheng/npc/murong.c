#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("慕容明珠",({"murong mingzhu","murong","mingzhu" }));
    	set("long","
一个英俊的少年，长身玉立，神采飞扬。束金冠，紫罗衫，腰悬着长剑，
剑鞘上的宝石闪闪生光，腰上还束着紫金带，剑穗上悬着龙眼般大的一
粒夜明珠。\n");

     	set("gender","男性");
    	set("age",22);
    	 	
    	set("combat_exp",6000000);  
    	set("attitude", "friendly");
    	
    	set("reward_npc",1);
    	set("difficulty",3);
	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"慕容明珠不屑地看了你一样说：“马空群也请你了？”\n"
    	}) );    	    	
    	
    	
	auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","sharen-sword",1);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": MAG"紫罗衫"NOR,
					"long": "一件紫罗衫。\n",
					 ]))->wear();  
    	carry_object("/obj/weapon/sword",([	"name": WHT"白玉拂尘剑"NOR,
						"long": "一把珠光宝气的长剑，更像是用来装饰的。\n",
						"value": 0,
					 ]))->wield();  
}
