inherit NPC;

void create()
{
    set_name("小喜鹊", ({ "bird" }) );
	set("race", "飞禽");
	set("age", 1);
    	set("long", "一只象征幸福吉祥的小喜鹊，叽叽喳喳不停地叫。\n");
	set("combat_exp",10000);

	set("chat_chance", 1);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"咭咭。\n",
		"喳喳。\n",
	}));
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
	setup();
}
