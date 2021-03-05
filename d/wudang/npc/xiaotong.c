// teacher.c

inherit NPC;

void create()
{
//      int i,amun;
        string *order = ({"魏", "陶"});
	string *orderr = ({"包包", "宝宝"});
        set_name( order[random(2)] + orderr[random(2)], ({ "kid", "small kid" }) );
	set("title", "无知小童");
	set("gender", "男性" );
	set("age", random(5)+4);
	set("int", 26);
	set("long",
		"他很小，很好欺负。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) );

	set("attitude", "peaceful");
	set("combat_exp", 2000);
        set_skill("unarmed", 1+random(10));
        set_skill("taiji", 10+random(10));
        map_skill("unarmed", "taiji");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}