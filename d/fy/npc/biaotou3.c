
inherit NPC;

void create()
{
        set_name("司马镖师", ({ "biaotou sima","biaotou"}) );
        set("gender", "男性" );
        set("age", 42);
		set("class","beggar");
		
		set("long", "这是一位金狮镖局的镖师。\n");
        set("combat_exp", 2800000);
        set("attitude", "friendly");
                
        set_skill("unarmed", 200);
        set_skill("dragonstrike",170);
		set_skill("dodge", 150);
		set_skill("move",200);
		set_skill("parry",170);
		set_skill("puti-steps",200);
	
		map_skill("dodge","puti-steps");
		map_skill("unarmed","dragonstrike");
	
        set("chat_chance", 1);
        set("chat_msg", ({
                "司马镖师打了个哈欠说，该睡觉了。\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
	if (!random(2))
	carry_object(__DIR__"obj/hongbao");

}

