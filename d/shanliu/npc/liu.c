// yangfan.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("柳风骨", ({ "liu fenggu","liu" }) );
	set("gender", "男性" );
	set("age", 35);
	set("title",HIC"江南第一儒侠"NOR);
	set("long",
"一个成熟、英俊、满洒的中年人，带着种中年男人特有的魁力。这人便然是江南第一儒侠柳风骨。\n" );
        set("chat_chance", 1);
        set("chat_msg", ({
            "柳风骨恨恨地道：山流的主人到底是谁？为什么我费尽心机寻到此处，便没了线索。\n",
    }) );
	set("combat_exp", 5000000);
	set("attitude", "friendly");
	set("per",1);
	set("str", 50);
	set("force",2000);
	set("max_force",2000);
	set("force_factor",50);
	set_skill("dodge",300);
        set_skill("unarmed",200);
        set_skill("parry", 200);
        setup();
	carry_object("/obj/armor/cloth")->wear();

}

