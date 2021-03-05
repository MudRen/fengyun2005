#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("白衣壮汉",({"whitecloth guard","guard"}));
	set("title","万马堂");
   	set("long","
白衣壮汉，万马堂的守卫，是马空群从各地招募来的好手。俗话说，
单拳难敌双手，好汉打不过人多，想进万马堂，硬闯那是太难了。\n");

     	set("gender","男性");
    	set("age",42);
    	set("group","wanmatang");
    	 	
    	set("combat_exp",5000000);  
    	set("attitude", "friendly");
    	   	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("busy_immune",random(2)+1);
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(100) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		name()+"道：“万马堂特别卫队，誓死捍卫萨达。。三堂主。”\n"
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","smallguy",1);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "短打劲装",
    						"long": "一件短打劲装。\n",
    						 ]))->wear();    
}
