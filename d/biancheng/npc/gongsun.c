#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("公孙断",({"gongsun duan","gongsun"}));
    	set("title","虬髯巨汉");
    	set("long","
这人满脸虬髯，一身白衣，腰里系着一尺宽的牛皮带，皮带上斜插着
把银鞘乌柄的奇形弯刀，手里还端着杯酒。酒杯在他手里，看来并不
太大，但别的人用两只手也未必能捧得住。\n");

     	set("gender","男性");
    	set("age",42);
    	 	
    	set("combat_exp",7500000);  
    	set("attitude", "heroism");
    	
    	set("reward_npc",1);
    	set("difficulty",5);
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
        set("smartnpc_busy",1);
        
    	set("chat_chance",1);
    	set("chat_msg",({
		"虬髯巨汉点点头，道：“我叫公孙断，我是个粗人，请进。”\n"
    	}) );    	    	
    	    	
		auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","bat-blade",2);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object("/obj/weapon/blade/blade_gongsun")->wield();
}
