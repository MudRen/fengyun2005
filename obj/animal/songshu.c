#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("小松鼠", ({ "squirrel", "song shu" }) );
    	set("race", "野兽");
    	set("age", 3);
    	set("long", "一个有着灵活眼睛的小松鼠。\n");
    	set("max_kee", 120);

	set("chat_chance", 1);
	set("chat_msg", ({
		"小松鼠在树下跳跃着。\n",
		"小松鼠捡起了一个松果啃了两口，又随手把它甩到一边。\n",
		(: random_move :)
	}) );
    	set_skill("dodge", 100);
	set("combat_exp", 100);

    	setup();
}


