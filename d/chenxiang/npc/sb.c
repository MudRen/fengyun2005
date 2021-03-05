// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("沉香哨兵", ({ "shaobing", "bing" }) );
        set("long",
                "正在上哨的哨兵，他负责整个小城的安全。\n");
        set("attitude", "heroism");
	set("vendetta_mark", "authority");
        set("combat_exp", random(5000000));

        set_skill("unarmed", 200);
        set_skill("staff", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("move", 200);

        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/damage", 30+random(100));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
			"沉香哨兵喃喃道：今天真是静的出奇．．．\n"
        }) );

        setup();

        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/yjing")->wield();
}


