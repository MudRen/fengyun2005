// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("和尚", ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("class","shaolin");
        set("age",random(20)+ 32);
	set("nickname","门僧");
        set("long", "这是少林寺专看后门的门僧。\n");
	set("vendetta_mark","shaolin");
        create_family("少林寺", 19, "弟子");
        set("combat_exp", 1000000);
        
        set("attitude", "friendly");
        set("agi", "10");
        
        set_skill("whip", 100);
	set_skill("tianlongwhip",100);
	set_skill("move",100);
	set_skill("puti-steps",100);
	set_skill("dodge",100);
	set_skill("force",100);
	set_skill("parry",100);
	set_skill("unarmed",100);
	set_skill("dabei-strike",100);
	
	map_skill("parry","tianlongwhip");
	map_skill("unarmed","dabei-strike");
	map_skill("dodge","puti-steps");
	map_skill("whip", "tianlongwhip");
	
        set("chat_chance_combat", 1);
	set("chat_msg_combat", ({
//              (: perform_action, "whip.sijiaotianlong" :),
        	(: perform_action, "unarmed.qianshouqianbian" :),
        }) );
        
        setup();
	carry_object(__DIR__"obj/monk22_cloth")->wear();
	carry_object(__DIR__"obj/whip")->wield();
}

