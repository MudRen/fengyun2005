
inherit NPC;

void create()
{
        set_name("大绵羊", ({ "sheep" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只全身雪白的的绵羊。\n");

	set("str",25);
        set("combat_exp", 25000);

        setup();
}

