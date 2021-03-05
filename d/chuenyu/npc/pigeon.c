
inherit NPC;

void create()
{
        set_name("信鸽", ({ "pigeon" }) );
        set("race", "飞禽");
        set("age", 2);
        set("long", "一只乖巧的小信鸽。\n");

        set_skill("dodge", 250);
		set("combat_exp", 3000);
        setup();
}

