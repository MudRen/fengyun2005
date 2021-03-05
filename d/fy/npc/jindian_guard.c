#include <ansi.h>
inherit NPC;

void create()
{
    	set_name(HIY"金殿武士"NOR, ({ "palace guard","guard"}) );
    	set("long",
    		"一个金盔金甲，手拎金瓜的武士。 \n");
	set("attitude", "heroism");
	set("vendetta_mark", "authority");
	

	set("combat_exp", 50000000);
	set_skill("unarmed", 300);
	set_skill("staff", 300);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set_skill("move", 300);
	set_skill("hammer",300);
	set_skill("pangu-hammer",200);
	set_skill("fengyu-piaoxiang",400);
	
	map_skill("hammer","pangu-hammer");
	map_skill("dodge","fengyu-piaoxiang");
	map_skill("move","fengyu-piaoxiang");
	
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 70);
	
	set("chat_chance", 1);
	set("chat_msg", ({
	
	}) );
	
	setup();
	
	carry_object(__DIR__"obj/jinjia")->wear();
	carry_object(__DIR__"obj/jinchui")->wield();
	carry_object(__DIR__"obj/jinkui")->wear();
}

