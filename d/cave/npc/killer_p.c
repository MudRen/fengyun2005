inherit NPC;
#include <ansi.h>

void create()
{
	set_name("氐土貉", ({ "killer p","killer" }) );
	set("title",HIC"青龙杀手"NOR);
	set("gender", "男性" );
	set("age", 42);
	set("long",
		"此人黑布蒙面，在漆黑的坑道中只有兵刃在闪光。\n");
	set("attitude", "friendly");
	set("combat_exp", 1600000);
    set("attitude", "friendly");
    set("class","wudang");
    set("cave_killer",1);
        
    set_skill("unarmed", 150);
    set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("blade",150);
	set_skill("taiji-sword",150);
	set_skill("five-steps",150);
	set_skill("move",150);
	set_skill("sword",150);
	set_skill("taiji",150);
	
	map_skill("dodge","five-steps");
	map_skill("move","five-steps");
	map_skill("sword","taiji-sword");
	map_skill("parry","taiji-sword");
	map_skill("unarmed","taiji");
	
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

