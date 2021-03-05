// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("杜吟", ({ "du yin", "du"}) );
        set("gender", "男性" );
        set("age",22);
        set("long", "一个黄山派弟子。\n");
        create_family("黄山派", 6, "弟子");
        set("combat_exp", 80000);
           
        set("attitude", "friendly");
        
        set_skill("unarmed", 60+random(100));
	set_skill("yunwu-strike",random(50)+30);
	set_skill("move",40 );
	set_skill("force",20);
	set_skill("dodge",100);
	set_skill("liuquan-steps",40);
	
	map_skill("dodge","liuquan-steps");
        map_skill("unarmed", "yunwu-strike");
        
        set("chat_chance", 5);
        set("chat_msg", ({
		"杜吟拱手微笑道：是找本派掌门吗？\n",
        }) );
        
        set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: perform_action, "unarmed.miwu" :),
        }) );
        
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

