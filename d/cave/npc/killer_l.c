inherit NPC;
#include <ansi.h>

void smart_fight();
void smart_busy();
void smart_attack();


void create()
{
	set_name("室火猪", ({ "killer l","killer" }) );
	set("title",HIC"青龙杀手"NOR);
	set("gender", "男性" );
	set("age", 42);
	set("long",	"此人黑布蒙面，在漆黑的坑道中只有兵刃在闪光。\n");
	set("attitude", "friendly");
	set("combat_exp", 1500000);
    set("attitude", "friendly");
    set("class","shaolin");
    set("cave_killer",1);
        
    set_skill("hammer", 150);
	set_skill("liuxing-hammer",150);
	set_skill("dodge",150);
	set_skill("move",180);
	set_skill("force",200);
	set_skill("puti-steps",150);
	set_skill("dabei-strike",150);
	
	map_skill("unarmed","dabei-strike");
	map_skill("dodge","puti-steps");
	map_skill("hammer", "liuxing-hammer");
	map_skill("parry","liuxing-hammer");
	
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        	(: ccommand("perform fanbei") :),    
        }) );

	setup();
	carry_object("/obj/armor/cloth")->wear();
    carry_object("/d/shaolin/npc/obj/hammer")->wield();
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

