inherit NPC;

void create()
{
        set_name("考生", ({ "examinee","student"}) );
        set("gender", "男性" );
        set("age", 12+ random(10));
        set("attitude", "friendly");
        set("long", "这是一位正在考试的考生。\n");
                
        set("combat_exp", 50000);
        
        set_skill("dodge", 100);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "考生抬起头，四下望了一眼．．．\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

