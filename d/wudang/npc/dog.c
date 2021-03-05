// dog.c

inherit NPC;

void create()
{
	set_name("野狗", ({ "dog" }) );
	set("race", "野兽");
	set("age", 3);
	set("long", "一只浑身脏兮兮的野狗。\n");

	set("chat_chance", 6);
	set("chat_msg", ({
		(: random_move :),
		"野狗用鼻子闻了闻你的脚。\n",
		"野狗在你的脚边挨挨擦擦的，想讨东西吃。\n",
		"野狗对著你摇了摇尾巴。\n",
		"野狗用後腿抓了抓自己的耳朵。\n" }) );
	set("combat_exp",2000);		
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

	setup();
}

