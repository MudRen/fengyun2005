// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("老山羊", ({ "oldman", "man" }) );
        set("long","一个很老的老屋人\n");
        set("attitude", "heroism");
	set("age",75);
        set("combat_exp", 100000);

        set_skill("unarmed", 70+random(50));
        set_skill("parry", 70+random(50));
        set_skill("dodge", 70+random(50));
        set_skill("move", 100+random(50));
        set_skill("flying-dragon", random(50)+10);
        set_skill("zuixian-steps",70+random(10));
	map_skill("dodge","zuixian-steps");
	map_skill("unarmed","flying-dragon");
	
	set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.longwujiutian" :),
        }) );

        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/bigcloth")->wear();
}
