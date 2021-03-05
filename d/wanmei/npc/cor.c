
inherit NPC;
void use_poison();

void create()
{
        set_name("鳄鱼", ({ "cor" }) );
        set("race", "野兽");
        set("age", 4);
		set("long", "一条水桶般粗的鳄鱼。\n");

        set("attitude", "aggressive");
        set_skill("dodge", 50);
		
        set("combat_exp", 10000);
		set("bellicosity", 300 );
        add_temp("apply/damage",10+random(10));
        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}

