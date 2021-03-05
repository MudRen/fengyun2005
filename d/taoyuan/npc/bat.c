inherit NPC;

void create()
{
        set_name("吸血蝙蝠", ({ "bian fu" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", 
	"专门躲在暗处的吸血蝙蝠。\n"
	);
        set("max_kee", 150);
        set("limbs", ({ "头部", "身体", "前脚", "後脚", }) );
        set("verbs", ({ "bite" }) );

	set("combat_exp", 500);
        set_skill("dodge", 120);


        setup();
}

