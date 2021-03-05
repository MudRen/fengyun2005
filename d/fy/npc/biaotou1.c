inherit NPC;

void create()
{
        set_name("欧阳镖师", ({ "biaotou ouyang", "biaotou"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一位金狮镖局的镖师。\n");
        set("combat_exp", 2500000);
        set("attitude", "friendly");
        
        set_skill("unarmed", 150);
        set_skill("changquan",200);
	set_skill("dodge", 150);
	set_skill("move",200);
	set_skill("parry",150);
	set_skill("puti-steps",150);
	
	map_skill("dodge","puti-steps");
	map_skill("unarmed","changquan");
	
        set("chat_chance", 1);
        set("chat_msg", ({
              "欧阳镖师打了个哈欠说，该睡觉了。\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
	if (!random(2))
		carry_object(__DIR__"obj/hongbao");

}
