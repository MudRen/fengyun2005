// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("买鱼的小姑娘", ({ "fishbuyer" }) );
	set("gender", "女性" );
	set("age", 15);
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",20);
        set("chat_chance", 5);
        set("chat_msg", ({
                "买鱼的小姑娘问道：这鱼怎么卖？\n",
                "买鱼的小姑娘道：八文一斤卖不卖？\n",
        }) );

	setup();
	carry_object("/obj/armor/cloth")->wear();
}
