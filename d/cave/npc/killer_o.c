inherit NPC;
#include <ansi.h>

void create()
{
	set_name("亢金龙", ({ "killer o","killer" }) );
	set("title",HIC"青龙杀手"NOR);
	set("gender", "男性" );
	set("age", 42);
	set("long",
		"此人黑布蒙面，在漆黑的坑道中只有兵刃在闪光。\n");
	set("attitude", "friendly");
	set("combat_exp", 1600000);
        set("attitude", "friendly");
        set("class","beggar");
        set("cave_killer",1);
        
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("huntunforce", 150);
		set_skill("staff",150);
		set_skill("dagou-stick",130);
		set_skill("doggiesteps",150);
		set_skill("dragonstrike",130);
        
        map_skill("unarmed","dragonstrike");
        map_skill("force", "huntunforce");
        map_skill("staff","dagou-stick");
        map_skill("dodge","doggiesteps");
        map_skill("parry","dagou-stick");
        map_skill("move","doggiesteps");
	
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
        	(: ccommand("perform tianxiawugou") :),    
        }) );

	setup();
	
	carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/staff")->wield();
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
