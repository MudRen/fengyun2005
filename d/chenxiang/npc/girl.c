// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("农家女", ({ "nongnu" }) );
	set("gender", "女性" );
	set("age", 15);
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",20);
	set("arrive_msg", "蹦蹦跳跳地跑了过来");
	set("leave_msg", "跑开了");
        set("chat_chance", 2);
        set("chat_msg", ({
                "农家女笑道：请你一起踢，好不好吗？\n",
                "农家女拿起鸡毛毽子踢了几下。\n",
		 (: random_move :)

        }) );

	setup();
	carry_object(__DIR__"obj/jianzi");
	carry_object("/obj/armor/cloth")->wear();
}
