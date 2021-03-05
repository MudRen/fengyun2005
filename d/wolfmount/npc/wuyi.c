#include <ansi.h>

inherit NPC;

void create()
{
    	set_name("常无意", ({ "chang wuyi","wuyi" }) );
	set("gender", "男性");
	set("title", "剥皮匠");
	set("age", 35);
	set("long","一个专门剥人皮的皮匠，他的眼睛如同刀锋一般锋利。\n");
        set("combat_exp", 1000000);
	set("attitude", "heroism");

	set_skill("move", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("bai-quan",100);
	set_skill("literate", 100);
	set_skill("sword",100);
	set_skill("qingpingsword",120);
	set_skill("qingpingforce",100);
	set_skill("chaos-steps",100);
	set_skill("perception", 100);
	    
	map_skill("force", "qingpingforce");
	map_skill("parry","qingpingsword");
	map_skill("sword","qingpingsword");
	map_skill("dodge","chaos-steps");
	map_skill("move","chaos-steps"); 
	map_skill("unarmed","bai-quan"); 
	
	setup();
        carry_object(__DIR__"obj/softsword")->wield();
        carry_object(__DIR__"obj/tigercloth")->wear();

}

void die()
{
	object ob, owner;
	
	
	if (objectp(ob = query_temp("last_damage_from")))
	{
		if (objectp(owner = ob->query_temp("possessed")))
			ob = owner;
		ob->set_temp("marks/wolf_killed_wuyi",1);
	}
	
	::die();
}				
