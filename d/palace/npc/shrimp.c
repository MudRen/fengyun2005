
inherit NPC;

void create()
{
        set_name("虾", ({ "shrimp" }) );
        set("race", "游鱼");
        set("age", 5);
        set("long", "一头虾头虾脑的野虾。 \n");
        set_skill("dodge", 80);
	set("combat_exp",2000);
        setup();
}
