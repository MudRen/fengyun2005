// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("恶魔", ({ "mo", "er mo" }) );
        set("long",
                "专门逼良为娼的恶魔。\n");

        set("pursuer", 1);

        set("combat_exp", 300000 + random(100000));

        set_skill("unarmed", 100);
        set_skill("sword", 50+random(100));
        set_skill("parry", 50+random(100));
        set_skill("dodge", 50+random(100));
        set_skill("move", 10+random(100));

        set_temp("apply/attack", 70);
		set_temp("apply/dodge", 70);
		set_temp("apply/parry", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/move", 100);

        setup();

        carry_object("/obj/armor/cloth")->wear();
}


void init()
{
	object me;
	me = this_player();
	if( interactive(me) ) { this_object()->kill_ob(me);
				me->kill_ob(this_object());
				}

}



int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}

