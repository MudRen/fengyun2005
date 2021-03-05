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
	
	set_skill("dodge", 200);
	set_skill("force", 200);
	set_skill("jingxing",150);
	set_skill("sword", 250);
	set_skill("jinhong-steps",200);
	set_skill("unarmed",200);
	set_skill("flame-strike",200);
	set_skill("move",200);
	set_skill("lefthand-sword",200);
	set_skill("sharen-sword",200);
	set_skill("parry",200);
	set_skill("iron-cloth",150);
	set_skill("xisui",100);
	
	map_skill("iron-cloth","xisui");
	map_skill("parry","lefthand-sword");
	map_skill("unarmed","flame-strike");
	map_skill("dodge", "jinhong-steps");
	map_skill("sword", "sharen-sword");
	map_skill("force", "jingxing");

	set("env/no_tell",1);
	set("env/no_give",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/killersword")->wield();

}

