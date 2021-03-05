
inherit NPC;

void create()
{
        set_name("趟子手", ({ "tangzi shou", "tangzi"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位体态轻盈的趟子手。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("NO_KILL",1);
        set_skill("unarmed", 90);
		set_skill("dodge", 100);
		set_skill("parry", 100);
		set_skill("move",800);
		set_skill("changquan",100);
		map_skill("unarmed","changquan");
		set("chat_chance", 1);
        set("chat_msg", ({
                "趟子手说：唉，整天过这刀头上舔血的日子。\n",
                "趟子手说：这几天路上不太平，千万不要出事才好。\n",
                "趟子手说：老子保镖这么多年，还没杀过人呢。\n",
        }) );
	
		setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
}

void die(){
	object ob;
	
	if (ob = present("li biaotou",environment()))
		ob->add_temp("bandit/biaotou",1);
	
	::die();
}