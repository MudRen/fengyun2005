#include <ansi.h>
inherit NPC;

void create()
{
        set_name("凤栖梧", ({ "feng qiwu", "feng" }) );
        set("nickname","鸡犬不留");
        set("long","传说中的大盗，一生偷盗无数，号称“夜盗百户，鸡犬不留”。\n");
        set("age", 50);
        set("combat_exp", 1000000);

    	set("no_arrest",1);
    	    	   			
		set_skill("unarmed",150);
		set_skill("dodge",150);
		set_skill("parry",150);
		set_skill("nine-moon-claw",120);
		set_skill("nine-moon-steps",120);
				
		map_skill("unarmed", "nine-moon-claw");
		map_skill("dodge", "nine-moon-steps");
				
		setup();
        carry_object("/obj/armor/cloth")->wear();
}



void die()
{
	object ob;
	object owner;
	ob = query_temp("last_damage_from");

	if (objectp(ob))
	{
		if (objectp(owner = ob->query("possessed")))
			ob = owner;
		
		ob->set_temp("marks/fugui_killed_feng",1);
	}
	
	::die();
}


