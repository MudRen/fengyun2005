inherit NPC;

void create()
{
	set_name("鬣狗", ({ "hyena"}) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 6);
	set("long", "这是一只凶猛无比的鬣狗。\n");
	
	set("str", 48);
	set("cor", 52);
	set("cps", 22);

	set("max_kee", 1000);
	set("max_gin", 500);
	set("max_sen", 500);
	set("attitude", "aggressive");

	set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "鬣狗向天狂嚎几声。\n",
                "鬣狗眼里的绿光使你不寒而颤。\n"
        }) );
	
	set("combat_exp", 20000);
	set("bellicosity", 3000 );
	
	set_temp("apply/attack", 120);
	set_temp("apply/armor", 120);
	setup();
}


