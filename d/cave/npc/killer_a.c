inherit NPC;
#include <ansi.h>

void smart_fight();

void create()
{
	set_name("鬼金羊", ({ "killer a","killer" }) );
	set("title",HIC"青龙杀手"NOR);
	set("gender", "男性" );
	set("age", 42);
	set("long",	"此人黑布蒙面，在漆黑的坑道中只有兵刃在闪光。\n");
	set("attitude", "friendly");
	set("combat_exp", 1000000);
	set("attitude", "friendly");
    set("class","bat");
    set("cave_killer",1);
        
    set_skill("unarmed", 150);
    set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("blade",150);
	set_skill("bat-blade",110);
	set_skill("meng-steps",110);
	set_skill("move",200);
	set_skill("blade",150);
	set_skill("luoriquan",150);
	
	map_skill("dodge","meng-steps");
	map_skill("move","meng-steps");
	map_skill("blade","bat-blade");
	map_skill("parry","bat-blade");
	map_skill("unarmed","luoriquan");
	
	set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        	(: ccommand("perform shiwanshenmo") :),    
    }) );

	setup();
	carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/blade")->wield();
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
