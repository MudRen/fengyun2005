inherit NPC;
#include <ansi.h>

void create()
{
	set_name("轸火蚓", ({ "killer g","killer" }) );
	set("title",HIC"青龙杀手"NOR);
	set("gender", "男性" );
	set("age", 42);
	set("long",
		"此人黑布蒙面，在漆黑的坑道中只有兵刃在闪光。\n");
	set("attitude", "friendly");
	set("combat_exp", 1400000);
        set("attitude", "friendly");
        set("class","official");
        set("cave_killer",1);
        
	set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: ccommand("perform zonghengtianxia") :),
        }) );

	set_skill("flame-strike",150);
        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("spells", 100);
        set_skill("unarmed", 100);
        set_skill("spear", 150);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("manjianghong", 100);
	set_skill("yue-spear",120);
	set_skill("puti-steps",160);
        set_skill("cursism", 100);
        set_skill("necromancy", 100);    

        map_skill("force", "manjianghong");
        map_skill("spear","yue-spear");
        map_skill("dodge","puti-steps");
        map_skill("parry","yue-spear");
        map_skill("move","puti-steps");
        map_skill("unarmed","flame-strike");

		setup();
	
		carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/spear")->wield();
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
