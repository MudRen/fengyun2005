inherit NPC;

void create()
{
	set_name("百灵鸟", ({ "bird" }) );
	set("race", "飞禽");
	set("age", 1);
	set("long", "咭咭喳喳的一只小百灵鸟。\n");
	
	set("combat_exp",2000);
	set("chat_chance", 2);
	set("chat_msg", ({
		"咭咭。\n",
		"喳喳。\n",
	}));
	
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 10);
	setup();
	carry_object(AREA_TIEFLAG"npc/obj/tongue",(["name":"百灵鸟舌"]));
}
