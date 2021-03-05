#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("郭威",({"guo wei","guo","guowei"}));
	set("title","神刀");
   	set("long","
紫色长髯的老人，他已是个垂暮的老人，但站在那里，腰杆还是挺得笔直。
风吹着他的长髯，像银丝般飞卷着，他的眼睛里却布满血丝。\n");
     	set("gender","男性");
    	set("age",72);
    	set("group","guo");
    	 	
    	set("combat_exp",7500000);  
    	set("attitude", "friendly");
    	
    	set("reward_npc",1);
    	set("difficulty",3);
    	    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"郭威仰天大笑，叫道：“好，好孩子，不愧是姓郭的！” \n",
    	}) );    	    	
    	    	
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","shenji-blade",2);
	
	setup();
    	carry_object("/obj/armor/cloth",([	
    						"name":  WHT"白麻衣"NOR,
    						"long": "一件惨白的麻衣。\n",
    						 ]))->wear();
    	carry_object("/obj/weapon/blade",([
    						"name": "鬼头大刀",
    						"long": "一柄大刀，几乎有两尺来长。\n",
    						"value": 0,
    						  ]))->wield();  
}

/*
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        if(me->query("marks/wanma/棺材之谜"))
                        me->set_temp("marks/wanma/江湖五毒e",1);
        ::die();
}*/