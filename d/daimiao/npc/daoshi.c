// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	string *order=({"上茶", "扫地", "烧饭", "挑水", "砍柴","淘米"});
        set_name((order[random(5)]) +"的道士", ({ "daoshi", "dao"}) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这是岱庙的小道士，正在忙着。\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
		set_skill("dodge", 30);
		set_skill("force",30);
		set_skill("demon-steps",30);
		set_skill("taiji", 50);
		map_skill("unarmed","taiji");
		map_skill("dodge","demon-steps");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "小道士轻轻的掸了掸身上的尘土．．．\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/boom");
        carry_object("/obj/armor/cloth",([	"name": "粗布道袍",
    						"long": "一件粗布道袍。\n",
    						 ]))->wear();    
}

