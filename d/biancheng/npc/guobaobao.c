#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("郭宝宝",({"guo baobao","guo","baobao"}));
   	set("long","一个十岁的孩子，手里提着一柄大刀。他手里的刀几乎比他的人还长。\n");
     	set("gender","男性");
    	set("age",10);
    	set("group","guo");
    	
    	 	
    	set("combat_exp",200000);  
    	set("attitude", "friendly");
    	    	
    	set("death_msg",CYN"\n$N惨叫一声倒了下去。\n"NOR);  	
    	
    	set("chat_chance",1);
    	set("chat_msg",({
		"郭宝宝说：“你要杀我爷爷，所以我也要杀你！” \n"
    	}) );    	    	
    	 	
	auto_npc_setup("wang",100,100,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
	set("class","none");
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
