// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("小慕容", ({ "mu rong","murong"}) );
        set("gender", "女性" );
        set("age",18);
        set("long", "一个活泼伶俐的黄山派弟子。\n");
        create_family("黄山派", 5, "弟子");
        set("combat_exp", 5500000);
        set("attitude", "friendly");
		set("class","legend");
	    	
        set("chat_chance", 1);
        set("chat_msg", ({
		name()+"说道：师傅最喜欢我了．．．\n",
        }) );
        
 
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","diesword",1);
		setup();
		carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/sword",([	"name": "青竹剑",
						"long": "一把用黄山的竹子削成的长剑。\n",
					]))->wield();   
}

/*
void init()
{	
	object me;
    	::init();
    	if( interactive(me = this_player()) && !is_fighting())
    	if (me->query("marks/黄山学艺") && me->query("class")=="legend") {
    	   	remove_call_out("greeting");
               	call_out("greeting", 1, me);
    	}   
}

int greeting(object me)
{
    message_vision(CYN"$N说：去年我到你们那儿，铁少奶奶教了我几招，你看成不成？\n"NOR,this_object());
    message_vision(CYN"$N说：你多呆几天吧,师傅说我们可以互相学学。\n"NOR,this_object());  
    return 1;
}

int recognize_apprentice(object ob)
{
    	if (ob->query("marks/黄山学艺") && ob->query("class")=="legend") {
    	  	return 1;
    	}   
	return 0;
}*/