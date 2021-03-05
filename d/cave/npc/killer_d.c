inherit NPC;
#include <ansi.h>

void create()
{
	set_name("张月鹿", ({ "killer d","killer" }) );
	set("title",HIC"青龙杀手"NOR);
	set("gender", "男性" );
	set("age", 42);
	set("long",
		"此人黑布蒙面，在漆黑的坑道中只有兵刃在闪光。\n");
	set("attitude", "friendly");
	set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("class","wolfmount");
        set("cave_killer",1);
        
        set_skill("unarmed", 150);
        set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("xueyeqianzong",150);
	set_skill("move",200);
	set_skill("wolf-strike",150);
		
	map_skill("dodge","xueyeqianzong");
	map_skill("move","xueyeqianzong");
	map_skill("unarmed","wolf-strike");
	
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
        	(: ccommand("perform duanhou") :),    
        }) );

	setup();
	carry_object("/obj/armor/cloth")->wear();

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

void die(){
	environment()->set("cave_mine",time());
	::die();
}
