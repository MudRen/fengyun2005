// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();

void create()
{
    set_name("白玉魔", ({ "master yumo", "master"}) );
    set("nickname", HIW "神钩"NOR);
    set("gender", "男性" );
    set("reward_npc", 1);
    set("difficulty", 4);
    set("age", 64);
    set("per", 35);
    set("class","beggar");
    set("attitude","friendly");
    
    set("pursuer", 1);
    
    set("long", "现任天下第一大帮的帮主的师叔，曾经因奸淫过度被前老帮主任慈逐出丐帮。\n");
    create_family("丐帮", 6, "师叔");
    set("rank_nogen",1);
    set("ranks",({"堂外弟子","一袋弟子","两袋弟子","三袋弟子","四袋弟子",
                      "五袋弟子","六袋弟子","七袋弟子","八袋弟子","九袋弟子",
                      "长老","副帮主"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));

    set("combat_exp", 2000000);
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","dagou-stick",1);
    setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object(__DIR__"obj/staff")->wield();
}

void attempt_apprentice(object me)
{
    	command("grin");
        command("say 你我好象不是一路人吗！\n");
}


int heal_up()
{
	if(environment() && !is_fighting() && !is_busy()
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}