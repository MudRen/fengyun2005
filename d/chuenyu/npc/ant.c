
inherit NPC;

void create()
{
        set_name("蚂蚁", ({ "ant" }) );
        set("race", "昆虫");
        set("subrace","爬虫");
        set("age", 1);
        set("long", "一只小小的小蚂蚁。\n");
        set("max_kee", 1);
         set("combat_exp", 3000);
        set_skill("dodge", 200);

        setup();
}

