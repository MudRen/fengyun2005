
inherit NPC;

void create()
{
        set_name("诸葛镖师", ({ "biaotou zhuge","biaotou"}) );
        set("gender", "男性" );
        set("age", 42);
	
		set("long", "这是一位金狮镖局的镖师。\n");
        set("combat_exp", 3200000);
        set("attitude", "friendly");
		set("class","assassin");        
        
        set_skill("unarmed", 200);
        set_skill("flame-strike",170);
		set_skill("dodge", 200);
		set_skill("move",200);
		set_skill("parry",200);
		set_skill("puti-steps",180);
		set_skill("move",200);
		
		map_skill("dodge","puti-steps");
		map_skill("unarmed","flame-strike");
		map_skill("move","puti-steps");

        set("chat_chance", 1);
        set("chat_msg", ({
                "诸葛镖师打了个哈欠说，该睡觉了。\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
	if (!random(2))
	carry_object(__DIR__"obj/hongbao");

}

