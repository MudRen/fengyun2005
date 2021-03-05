// mind_beast.c

inherit NPC;

void create()
{
    	set_name("瘦马", ({ "horse" }) );
	set("race", "家畜");
	set("gender", "雄性");
	set("age", 3);
    	set("long", "一匹瘦马，胸口肋骨高高凸起，四条长腿肌肉尽消，宛似枯柴，毛皮零零落落，\n生满了癞子。\n");
	

    	set("max_kee", 1000);
	set("max_gin", 600);
	set("max_sen", 900);
	set("attitude", "peaceful");
	
        set("chat_chance", 1);
        set("chat_msg", ({
     		"瘦马＂咴～～咴咴＂地悲嘶了几声\n",
        }) );
	
	set("combat_exp", 20000);
	set_temp("apply/attack", 60);
	set_temp("apply/dodge",40);
	setup();
}
