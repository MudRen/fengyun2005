// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("李神童", ({ "li", "tong" }) );
        set("long","一个带着绿高帽的李神童\n");
		set("title", HIG "绿高帽"NOR);
        set("attitude", "heroism");
		set("age",55);
        set("combat_exp", 200000);

        set_skill("unarmed", 70+random(50));
        set_skill("parry", 70+random(50));
        set_skill("dodge", 70+random(50));
        set_skill("move", 100+random(50));
        set_skill("changquan", 70+random(100));
        set_skill("jinhong-steps",70+random(10));
		
		map_skill("dodge","jinhong-steps");
		map_skill("unarmed","changquan");
	
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/damage", 30);

        setup();

        carry_object(__DIR__"obj/bigcloth")->wear();
}
