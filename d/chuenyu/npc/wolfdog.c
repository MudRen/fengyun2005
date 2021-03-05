// mind_beast.c

inherit NPC;

void create()
{
	set_name("巨型犬", ({ "wolf dog", "dog" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 3);
	set("long", "这是一只凶猛无比，半人多高的巨型狼犬。\n");
	
	set("str", 48);

	set("max_kee", 600);
	set("max_gin", 600);
	set("max_sen", 900);
	
	set("attitude", "aggressive");
	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 1);
        set("chat_msg", ({
		"巨型犬向你疯狂的哮道：呜汪！呜汪！呜汪！呜汪！",
        }) );
                set("chat_msg_combat", ({
		"巨型犬向你疯狂的哮道：呜汪！呜汪！呜汪！呜汪！",
        }) );

	set("combat_exp", 20000);
	set("bellicosity", 3000 );
	
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 40);
	setup();
}
