#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("丁灵中",({"ding lingzhong","ding","lingzhong"}));
	set("title","丁家庄 三少爷");
   	set("long","长身玉立，英俊的脸上伤痕犹在，正是风采翩翩的丁三少爷。
\n");
     	set("gender","男性");
    	set("age",32);
    	 	
	set("reward_npc",1);
    	set("difficulty",5);
	
    	set("combat_exp",4000000);  
    	set("attitude", "friendly");
    	
    	
    	set("death_msg",CYN"\n$N悔恨地说：“我的剑。。还是。。。拔得。。太。。慢。。”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"李马虎笑眯眯地道：“女人用鸡蛋清洗脸，越洗越年轻的。”\n",
    	}) );    	    	
    	
    	
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
    
}
