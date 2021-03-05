inherit NPC;
#include <ansi.h>

void create()
{
	set_name("宫装美婢", ({ "slave girl","girl" }) );
	set("gender", "女性" );
	set("title", MAG "楚楚动人"NOR);
	set("age", 18);
	set("long",
		"一个身穿素色宫装的少女，斜依在虎皮缛旁，弄着管弦。。\n");
	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("per",30);
        set("chat_chance", 1);
        set("chat_msg", ({
		"宫装美婢轻拨瑶琴，一副心神俱醉的样子。。\n",
	}) );
	set_skill("unarmed",20);
	set_skill("dodge",100);
	setup();
	carry_object(__DIR__"obj/gongzhuang")->wear();
}
