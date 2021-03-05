inherit __DIR__"player";
#include <ansi.h>

void create()
{

	set_name("黑衣蒙面人", ({ "assassin" }) );
	set("class","assassin");
	set("gender", "男性" );
	set("age", 25);
	set("dark_npc",1);
	
//	set("nickname",HIB"龙"HIR"凤"HIY"奇"HIW"翔"NOR);
	
	set("title","青龙杀手");
	set("per",80);
	set("attitude", "friendly");
	set("combat_exp", 4000000);
	set("achieved_level", 79);
	
	set_skill("unarmed", 180);
		
		set_skill("advanced-unarmed", 200);
		
		set_skill("chanting", 150);
		set_skill("foreknowledge",100);
		set_skill("perception",100);
		set_skill("sword", 300);
		set_skill("force", 160);
		set_skill("parry", 200);
		set_skill("dodge", 160);
		set_skill("move",160);
		set_skill("literate",100);
		    
		set_skill("nine-moon-spirit", 200);	
		set_skill("nine-moon-sword", 200);
		set_skill("nine-moon-claw", 200);
		set_skill("nine-moon-steps", 180);
		set_skill("nine-moon-force", 180);
		
		set_skill("qingpingsword",200);
    	set_skill("qingpingforce",150);
    	set_skill("chaos-steps",150);
    	set_skill("bai-quan", 200);
		    
		map_skill("dodge", "nine-moon-steps");
		map_skill("unarmed", "nine-moon-claw");
		map_skill("force", "nine-moon-force");
		map_skill("sword", "nine-moon-sword");
		map_skill("move","nine-moon-steps");

	set("env/no_tell",1);
	set("env/no_give",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/killersword")->wield();
}

