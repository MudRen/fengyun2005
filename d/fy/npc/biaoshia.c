
inherit NPC;

void create()
{
        set_name("镖师", ({ "biao shi"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位高达六尺的镖师。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("NO_KILL",1);
        set_skill("hammer", 90);
	set_skill("dodge", 100);
	set_skill("move",800);
	set_skill("parry",100);
	set_skill("force",100);
	
        set("chat_chance", 1);
        set("chat_msg", ({
                "镖师说：在家靠兄弟，出门靠朋友，这行当讲的就是交情。\n",
                "镖师说：金狮镖局这面旗子，江湖上谁不给三分面子？\n",
                "镖师望了望自己粗壮的胳膊，又捏了两下，脸上露出得意之色。\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object(__DIR__"obj/stonehammer")->wield();
}

void die(){
	object ob;
	
	if (ob = present("li biaotou",environment()))
		ob->add_temp("bandit/biaotou",1);
	
	::die();
}