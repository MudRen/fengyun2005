inherit NPC;
#include <ansi.h>

void create()
{
	set_name("斗木獬", ({ "killer h","killer" }) );
	set("title",HIC"青龙杀手"NOR);
	set("gender", "男性" );
	set("age", 42);
	set("long",
		"此人黑布蒙面，在漆黑的坑道中只有兵刃在闪光。\n");
		set("attitude", "friendly");
		set("combat_exp", 1400000);
        set("attitude", "friendly");
        set("class","taoist");
		set("cave_killer",1);
		
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: ccommand("cast netherbolt") :),
        }) );

        set_skill("move", 150);
        set_skill("force", 200);
        set_skill("spells", 100);
        set_skill("unarmed", 120);
        set_skill("sword", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("gouyee", 120);
        set_skill("notracesnow",120);
        set_skill("taoism", 120);
        set_skill("necromancy", 100);            
		set_skill("snowshade-sword",120);

		map_skill("force", "gouyee");
		map_skill("unarmed","tenderzhi");
		map_skill("dodge","notracesnow");
		map_skill("spells", "necromancy");
		map_skill("parry", "snowshade-sword");
		map_skill("sword", "snowshade-sword");

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
