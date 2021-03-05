#include <ansi.h>

inherit NPC;

void create()
{
        set_name("狱卒", ({ "prison guard", "guard" }) );
        set("long", "这是黑松堡的狱卒。\n");
        set("attitude", "heroism");

        set("str", 27);
        set("combat_exp", 10000);

        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
               (: random_move :),
        }) );

        set_skill("unarmed", 20);
        set_skill("sword", 30);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("move", 100);

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/sword1")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
		kill_ob(ob);
        }
}
 
