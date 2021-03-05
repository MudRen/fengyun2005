
inherit NPC;

void create()
{
        set_name("小羊羔", ({ "sheep" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一只全身雪白的的绵羊。\n");

		set("str",15);
        set("combat_exp", 15000);

        setup();
}

