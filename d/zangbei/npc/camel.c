inherit NPC;
#include <ansi.h>

void create()
{
    	set_name("单峰雄驼", ({ "male camel","camel" }) );
	set("race", "家畜");
	set("gender", "雄性");
	set("age", 3);
    	set("long", "一匹大漠中常见的单峰骆驼，正在湖边歇息。\n");
        
	set("attitude", "peaceful");
	
        set("chat_chance", 1);
        set("chat_msg", ({
     		CYN"骆驼低下头去啃了几口青草，转首打量了你几眼，毫无兴趣。\n"NOR,
        }) );
        set("combat_exp", 3000000);
	set_temp("apply/attack", 300);
	set_temp("apply/armor", 100);
	set_temp("apply/dodge",300);
	set_temp("apply/damage",200);
	setup();
	carry_object(__DIR__"obj/an")->wear();
}


void die(){
	object spouse;
	
	if (spouse=present("female camel",environment(this_object())))
	if (!userp(spouse)) {
		spouse->die_next();
	}
	::die();
}