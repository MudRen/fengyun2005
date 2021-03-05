// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("霍英", ({ "huo ying", "huo"}) );
        set("gender", "男性" );
        set("age",22);
        set("long", "一个黄山派弟子。\n");
        create_family("黄山派", 6, "弟子");
        set("combat_exp", 80000);
        set("attitude", "friendly");
        
        set_skill("unarmed", 60+random(10));
	set_skill("yunwu-strike",random(50)+30);
	set_skill("move",40);
	set_skill("force",20);
	set_skill("dodge",100);
	set_skill("liuquan-steps",40);
	map_skill("unarmed", "yunwu-strike");
	map_skill("dodge","liuquan-steps");
        
        set("chat_chance", 5);
        set("chat_msg", ({
		"霍英拱手微笑道：不知您到黄山有何贵干？\n",
        }) );
        
        set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: perform_action, "unarmed.miwu" :),
        }) );
        
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

