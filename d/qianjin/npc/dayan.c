
inherit NPC;

void create()
{
        set_name("大雁", ({ "yan" }) );
        set("race", "飞禽");
        set("age", 5);
        set("long", "一只灰色羽毛的大雁。\n");
        set_skill("dodge", 80);
	set("combat_exp", 10000);
        setup();
}

