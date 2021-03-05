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
        set("long", "这是崇福宫的小道士，正在忙着。\n");
        set("combat_exp", 12000);
        set("attitude", "friendly");
                
        set("chat_chance", 10);
        set("chat_msg", ({
                "小道士轻轻的叹了口气道：三清宫有什么了不起的，我就是在这打杂也不去！\n",
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

