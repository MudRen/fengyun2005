// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;

void create()
{
        set_name("白环", ({ "bai huan", "bai"}) );
        set("gender", "男性" );
        set("age",22);
        set("long", "一个佩刀的黄山派弟子。\n");
        create_family("黄山派", 6, "弟子");
        set("combat_exp", random(500000)+500000);
        set("attitude", "friendly");
		set("group", "bai");
		        
        set_skill("blade", 60+random(10));
	set_skill("qiusheng-blade",random(50)+30);
	set_skill("move",60);
	set_skill("force",20);
	set_skill("dodge",100);
	set_skill("liuquan-steps",40+random(40));
	set_skill("parry",50);
	map_skill("blade", "qiusheng-blade");
	map_skill("parry","qiusheng-blade");
	map_skill("dodge","liuquan-steps");
        
        set("chat_chance", 1);
        set("chat_msg", ({
		name()+"说道：你杀气真重！\n",
        }) );
        
        set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: perform_action, "blade.jingsheng" :),
        }) );
        
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/blade")->wield();
}

