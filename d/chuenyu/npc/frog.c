
inherit NPC;

void create()
{
        set_name("蛐蛐", ({ "insect" }) );
        set("race", "昆虫");
        set("subrace","爬虫");
        set("age", 1);
        set("long", "一只方头方脑的大蛐蛐。\n");
        set("max_kee", 1);
        
	set("combat_exp", 3000);
        set_skill("dodge", 150);

        setup();
}

