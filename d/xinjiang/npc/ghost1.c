inherit SMART_NPC;

void create()
{
        set_name("冤魂", ({ "crying ghost" }) );
        set("age", 45);
        set("env/wimpy", 50);

        set("combat_exp", 2000000);
        set("score", 200);
        
		set("perform_busy_d", "bat/dodge/fengyu-piaoxiang/zonghengsihai");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
        set_skill("move", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("unarmed", 150);
        set_skill("luoriquan",150);
        set_skill("fengyu-piaoxiang",200);
        
        map_skill("unarmed","luoriquan");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");    
           
        setup();
}

int is_ghost() { return 1; }

