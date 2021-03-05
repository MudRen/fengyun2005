inherit NPC;
#include <ansi.h>

void create()
{
    set_name("散花少女", ({ "flower girl","girl" }) );
	set("gender", "女性" );
	set("age", 18);
	set("long",
            "一个乌发垂肩，白衣如雪的少女，提著满篮黄菊红花，随意挥洒在花径上。\n");
        set("combat_exp", 80000);
	set("attitude", "friendly");
	set("per",30);
        set("chat_chance", 1);
        set("chat_msg", ({
        "散花少女纤手轻杨，挥洒着各式鲜花，银铃般的笑声荡漾在海边。\n",
        }) );
	set_skill("unarmed",20);
	set_skill("dodge",100);
	setup();
        carry_object(__DIR__"obj/baiqun")->wear();
}
