// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("瞎子", ({ "xia zi", "xia" }) );
        set("long","这是个正在寻视银钩赌坊的保镖。\n");
        set("attitude", "heroism");

        set("str", 20+random(10));
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 100000);

        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
	set_temp("apply/dodge", 70);
	set_temp("apply/parry", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object("/obj/armor/cloth")->wear();
}
