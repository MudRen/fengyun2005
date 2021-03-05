//Basic settings for the heroine

#include <ansi.h>
inherit __DIR__"event_npc";

void create()
{       

	set("age",18);
        set("per",50);
        set("agi",50);
        set("str",22);
        set("gender", "女性");
        set("attitude", "friendly");
        set("combat_exp", 500000);  
	    set("kee", 3000);
        set("max_kee", 3000);
	    set("gin", 3000);
        set("max_gin", 3000);
	    set("sen", 3000);
        set("max_sen", 3000);
        set_skill("meihua-shou",80);
        set_skill("unarmed",120);
        set_skill("force",120);
        set_skill("hanmei-force",200);
        set_skill("qidaoforce",200);        
        set_skill("move",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("fall-steps",150);
        set_skill("anxiang-steps",150);
        set_skill("cloud-dance",150);
        set_skill("tanzhi-shentong",150);
        set_skill("iron-cloth",100);
        set_skill("spring-water",200);
        set("ALWAYS_ACTIVE",1);
        set("force_factor",120);
        set("max_force",30000);
        set("force",30000);
        set("class", "huashan");
        map_skill("force","hanmei-force");
        map_skill("dodge","cloud-dance");
        map_skill("iron-cloth","spring-water");
        map_skill("move","anxiang-steps");
        map_skill("unarmed","tanzhi-shentong");

        

}
void leave_room();

void heart_beat()
{
	object hero;


	if(query("no_chasing")) return ::heart_beat();
	if(hero=query("following_person"))
	{
	if(environment(hero)!=environment())
		{		
		message_vision("$N飘然离去。\n",this_object());
		this_object()->move(environment(hero));
		message_vision("$N走了过来。\n",this_object());
		}
	}
	else
	{

	hero=query("event_person");
	if(hero&&environment(hero)==environment())	
	{
		if(query("leave_room")) delete("leave_room");
	}
	else 
	{
		add("leave_room",1);
		if(query("leave_room")==100)	
			leave_room();
	}
	}
	::heart_beat();
	
}
	
		

	
void init()
{
	object hero;
	
	::init();
	add_action("do_ask","ask");
}	
	
void leave_room()
{
	message_vision(HIW"仿佛在白雪红梅间渐渐融化了一个淡淡的影子，白衣如雪的身影消失在视野中。 \n"NOR,this_object());
	destruct(this_object());
}

