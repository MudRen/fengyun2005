//	看管少林鼓楼的和尚

inherit SMART_NPC;
void create()
{
//		string *name = ({"算","余","时","格","已","的","争","那","所","落","们","史"});
//      set_name("一"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        
        set_name("一格",({ "shaolin monk", "monk" }));
        set("gender", "男性" );
        set("age",random(20)+ 32);
        set("nickname","击鼓的");
		create_family("少林寺", 18, "弟子");
        set("long", "这是少林寺鼓楼上的和尚。\n");
		set("vendetta_mark","shaolin");
		set("vendetta_mark","shaolin");
        set("combat_exp", 3200000);
        set("attitude", "friendly");

        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"说道：是时候了吧？\n",
        }) );

	
		set("chat_chance_combat", 100);
	    set("chat_msg_combat", ({
		     (: auto_smart_fight(20) :),
	     }) ); 		
	
		auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","liuxing-hammer",1);
		
		setup();
		carry_object(__DIR__"obj/monk_cloth")->wear();
		carry_object(__DIR__"obj/hammer")->wield();
}