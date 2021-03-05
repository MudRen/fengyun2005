// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        string *name = ({"梦遗","梦幻","梦失","梦丢","梦寐","梦都","梦乡",
"梦初","梦空","梦园", "梦流"});
        
        set_name("梦失", ({ "shaolin monk", "monk"}));
        
        create_family("少林寺", 20, "弟子");
        set("class","shaolin");
        set("gender", "男性" );
        set("age",random(20)+ 32);
		set("nickname","棍僧");
        set("long", "这是少林寺的棍僧。\n");
		set("vendetta_mark","shaolin");
        set("combat_exp", 40000);
        set("attitude", "friendly");
		set("stickguy",	1);
		set("cps",80);
        set_skill("staff", 40+random(100));
		set_skill("xingyi-stick",random(100)+20);
		set_skill("move",400);
		set_skill("force",200);
		set_skill("parry",40);
		
		map_skill("staff", "xingyi-stick");
		map_skill("parry","xingyi-stick");
		
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "staff.powerjam" :),
        }) );

		setup();
		carry_object(__DIR__"obj/monk23_cloth")->wear();
		carry_object(__DIR__"obj/stick")->wield();
}

