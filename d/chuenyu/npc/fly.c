
inherit NPC;

void create()
{
        set_name("蝴蝶", ({ "butterfly" }) );
        set("race", "昆虫");
        set("subrace","飞虫");
        set("age", 1);
        set("long", "一只美丽的小蝴蝶。\n");
        set("max_kee",1);
        set_skill("dodge", 250);
        set("combat_exp", 3000);

        setup();
}

