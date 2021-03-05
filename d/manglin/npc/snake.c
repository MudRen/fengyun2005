
inherit NPC;

void create()
{
        set_name("紫斑巨蟒", ({ "snake" }) );
        set("race", "蛇类");
        set("age", 15);
        set("long", "一条水桶粗细的巨蟒。\n");

        
        set("attitude", "aggressive");
        set_skill("dodge", 200);
        set("combat_exp", 999999);
        set("agi", 10 );
	
	set("bellicosity", 30000 );
	set_temp("apply/attack",200);
	set_temp("apply/damage",150);
        setup();
}
