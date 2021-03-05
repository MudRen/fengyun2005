// mind_beast.c

inherit NPC;

void create()
{
	set_name("白额猛虎", ({ "tiger", "big tiger" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 20);
	set("long", "这是一只凶猛无比的白额猛虎。\n");
	
	set("attitude", "aggressive");

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "白额猛虎猛地向你一扑！\n",
                "白额猛虎狠狠地用尾巴向你扫来！\n"
        }) );

	set("combat_exp", 800000);
	set("bellicosity", 3000 );
	set("agi", 10 );
	
	set_temp("apply/attack", 160);
	set_temp("apply/armor", 20);

	setup();
}
