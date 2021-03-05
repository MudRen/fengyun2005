#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("紫衫少年",({"shaonian"}));
//    set("title","虬髯巨汉");
   	set("long","
一个英俊的少年，他的腰很细，肩很宽，长身玉立，神采飞扬。束金冠，
紫罗衫。\n");

     	set("gender","男性");
    	set("age",22);
		set("group","murong");
    	 	
    	set("combat_exp",5000000);  
    	set("attitude", "friendly");
    	
   	   	set("death_msg",CYN"\n$N悔恨地说：“我的剑。。还是。。。拔得。。太。。慢。。”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		name()+"忍不住冷笑：“关东万马堂，哼，好大的气派。”\n"
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","sharen-sword",1);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": MAG"紫罗衫"NOR,
    						"long": "一件紫罗衫。\n",
    						 ]))->wear();    
    
}
