inherit SMART_NPC;

void create()
{
        set_name("孟尝不花", ({ "buhua"}) );
        set("title","胖嫖客");
        set("gender", "男性" );
        set("long", "这是一位肥肥胖胖的大嫖客，在江湖上也小有名气，是“血魂镖局“的副局主孟尝不花。\n");
		set("age",47);
	
		set("combat_exp", 6000000);
        
	      
        set("chat_chance", 1);
        set("chat_msg", ({
		"孟尝不花骂道：怎么尽是拿些水货来蒙咱家，老子要见得的是血奴姑娘！\n",
        }) );
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		 (: auto_smart_fight(40) :),
        }) );
    	
    	
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","thunderwhip",1);
	
		setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/whip")->wield();
}

