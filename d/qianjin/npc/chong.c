
inherit NPC;

void create()
{
        set_name("萤火虫", ({ "cong" }) );
        set("race", "昆虫");
        set("age", 1);
        set("long", "一只亮晶晶的萤火虫。\n");
        set_skill("dodge", 200);
	set("combat_exp", 3000);
        setup();
}

