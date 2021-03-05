inherit NPC;
#include <ansi.h>

void create()
{
		set_name("虚日鼠", ({ "killer j","killer" }) );
		set("title",HIC"青龙杀手"NOR);
		set("gender", "男性" );
		set("age", 42);
		set("long",
			"此人黑布蒙面，在漆黑的坑道中只有兵刃在闪光。\n");
		set("attitude", "friendly");
		set("combat_exp", 1500000);
        set("attitude", "friendly");
        set("class","assassin");
        set("cave_killer",1);
        
		set_skill("unarmed",150);
 		set_skill("flame-strike",150);
 		set_skill("sword", 150);
    	set_skill("parry", 150);
    	set_skill("dodge", 150);
    	set_skill("move", 150);
    	set_skill("jinhong-steps",140);
		set_skill("lefthand-sword",150);
    	
    	map_skill("unarmed","flame-strike");
    	map_skill("dodge","jinhong-steps");
    	map_skill("move","jinhong-steps");
    	map_skill("parry","lefthand-sword");
    	map_skill("sword","lefthand-sword");
    	
    	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        	(: ccommand("perform duxin") :),    
        }) );      

		setup();
	
		carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

void die(){
	environment()->set("cave_mine",time());
	::die();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIW + name() + "一闪身，在黑暗中消失了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
