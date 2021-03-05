inherit NPC;
#include <ansi.h>

void smart_fight();
void smart_busy();
void smart_attack();


void create()
{
	set_name("危月燕", ({ "killer k","killer" }) );
	set("title",HIC"青龙杀手"NOR);
	set("gender", "女性" );
	set("age", 42);
	set("long",
		"此人黑布蒙面，在漆黑的坑道中只有兵刃在闪光。\n");
	set("attitude", "friendly");
	set("combat_exp", 1500000);
        set("attitude", "friendly");
        set("class","huashan");
        set("cave_killer",1);
        
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("throwing",150);            
        set_skill("hanmei-force", 100);
		set_skill("tanzhi-shentong",100);
		set_skill("anxiang-steps",120);
        set_skill("zhaixin-claw",120);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("force", "hanmei-force");
        map_skill("throwing","tanzhi-shentong");
        map_skill("dodge","anxiang-steps");
        map_skill("move","anxiang-steps");
	
		set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        	(: ccommand("perform mantianhuayu") :),    
        }) );

		setup();
	
		carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/dart")->wield();
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