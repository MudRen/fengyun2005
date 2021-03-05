#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("孙远超", ({ "sun yuanchao", "sun" }) );
	set("gender", "男性" );
	set("age", 28);
	set("class","shaolin");
	set("nickname", HIW"江里白龙"NOR);
	set("long", "他身材颀长，双目炯然，看上去一表人材。\n");
	
	set("combat_exp", 1300000);
	
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
    	 (: auto_smart_fight(50) :),
    }) );
        
	auto_npc_setup("wang",170,160,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
	setup();
	carry_object("/obj/armor/cloth",
		([ "name": "白衫" ])
		)->wear();
	carry_object("/obj/weapon/blade")->wield();
}


void die(){
	object me;
	
	if(objectp(me=query_temp("last_damage_from") ))
	{ 
		if (objectp(me->query("possessed")))
			me = me->query("possessed");
		environment(this_object())->check_rescue(me);	
	}	
	::die();
}

