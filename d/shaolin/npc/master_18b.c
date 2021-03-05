// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
#include <ansi.h>
int chant();

void create()
{
    	set_name("一强", ({ "master yi", "master"}) );
    	set("nickname", HIM "大法师"NOR);
    	set("vendetta_mark","shaolin");
    	create_family("少林寺", 18, "长老");
    	set("long","少林大法师，少林为武林第一名门正派，绝少败类，便都是他的功劳。\n");
    	set("gender", "男性" );
    	set("age", 64);
    	
    	set("attitude","friendly");
        set("combat_exp", 9200000);
    
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
    	    
    	auto_npc_setup("wang",200,220,0,"/obj/weapon/","fighter_w","chant",2);
    	setup();   	
    	carry_object("obj/armor/cloth",([	"name": "大法师服",
    						"long": "一件大法师服。\n",
    						 ]))->wear();   
}
