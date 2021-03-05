
inherit NPC;

void create()
{
        set_name("野鸭", ({ "duck" }) );
        set("race", "飞禽");
        set("age", 5);
        set("long", "一头野头野脑的野鸭子。 \n");
		set("combat_exp",2000);
        set_skill("dodge", 80);

        setup();
}
