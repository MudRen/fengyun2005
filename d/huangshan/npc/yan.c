// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("燕珊", ({ "yan shan", "yan"}) );
        set("gender", "女性" );
        set("age",22);
        set("long", "一个佩剑的黄山派弟子。\n");
        create_family("黄山派", 6, "弟子");
        set("combat_exp", 30000);
        set("attitude", "friendly");
        
        set_skill("sword", 60+random(10));
	set_skill("siqi-sword",random(50)+30);
	set_skill("move",60);
	set_skill("force",20);
	set_skill("dodge",100);
	set_skill("liuquan-steps",40+random(40));
	map_skill("sword", "siqi-sword");
	map_skill("dodge","liuquan-steps");
        
        set("chat_chance", 1);
        set("chat_msg", ({
		name()+"对你说道：你看！那石笋上好像有个人耶！\n",
        }) );
        
        set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: perform_action, "sword.siqi" :),
        }) );
        
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

