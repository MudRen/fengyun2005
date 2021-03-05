
inherit NPC;

void create()
{
        set_name("鱼", ({ "fish" }) );
        set("race", "游鱼");
        set("age", 5);
        set("long", "一条鱼头鱼脑的野鱼。\n");
        
        set_skill("dodge", 80);
	set("combat_exp",2000);
        setup();
}
