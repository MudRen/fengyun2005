inherit NPC;

void create()
{
        set_name("牦牛", ({ "bull" }) );
        set("race", "家畜");
        set("age", 10);
        set("long", "一只长着长长黑毛的西藏牦牛。\n");

	set("combat_exp", 300000);
	
        setup();
}

