// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	string *name = ({"算","余","时","格","已","的","争","那","所","落","们","史"});
        set_name("一"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("age",random(20)+ 32);
	create_family("少林寺", 18, "弟子");
        set("long", "这是少林寺的和尚\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(300000)+2000000);
        set("attitude", "friendly");
        

        set_skill("hammer", 70+random(100));
	set_skill("liuxing-hammer",random(100)+150);
	set_skill("dodge",200);
	set_skill("move",180);
	set_skill("force",200);
	set_skill("puti-steps",150);
	set_skill("dabei-strike",150);
	map_skill("unarmed","dabei-strike");
	map_skill("dodge","puti-steps");
	map_skill("hammer", "liuxing-hammer");
	map_skill("parry","liuxing-hammer");
	set("chat_chance", 2);
        set("chat_msg", ({
                name()+"说道：是时候了吧？\n",
        }) );
        set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		name()+"笑道：在少林寺撒野？\n",
                (: perform_action, "hammer.fanbei" :),
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );

	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/hammer")->wield();
}
