// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("风云大衙役", ({ "yayi", "ya" }) );
        set("long",
                "正在上堂的衙役，千万不要惹他们\n");

        set("attitude", "heroism");
	set("vendetta_mark", "authority");
	set("reward_npc", 1);
	set("difficulty", 5);

        set("cor", 40);
        set("cps", 25);

        set("combat_exp", 4000000);

        set_skill("unarmed", 200);
        set_skill("staff", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("move", 200);
	set_skill("fumostaff",200);
	set_skill("meihua-shou",150);
	set_skill("puti-steps",200);
	
	map_skill("dodge","puti-steps");
	map_skill("staff","fumostaff");
	map_skill("unarmed","meihua-shou");
	map_skill("parry","fumostaff");
	
        set("chat_chance", 1);
        set("chat_msg", ({
"风云衙役低声宣道：威～～～～武～～～～\n"
        }) );

        setup();

        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/sawei")->wield();
}

