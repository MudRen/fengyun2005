#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("金不换", ({ "jin buhuan", "jin" }) );
	set("gender", "男性" );
	set("nickname",HIM"见义不为"NOR);
        set("title","丐帮     九袋长老");
        set("quality","evil");
	set("age", 47);
	set("int", 25);
	set("per", 20);
	set("str", 30);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"一个鹑衣百结，满面麻子的独眼乞丐。\n");
        set("force_factor", 35);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 3700000);
        set("score", -16000);
        set("class","beggar");
        set("strategy","default");
        set("flee_rate",20);
        set("hunting",1);
        set_skill("unarmed", 250);
        set_skill("force", 280);
        set_skill("parry", 160);
        set_skill("literate", 130);
	set_skill("dodge", 350);
	set_skill("huntunforce",150);
	set_skill("doggiesteps",200);
	set_skill("dragonstrike", 150);
	map_skill("unarmed", "dragonstrike");
	map_skill("dodge","doggiesteps");
	map_skill("force","huntunforce");
	set("chat_chance",2);
	set("chat_msg",	({
	"金不换目中露出仇恨的怒火，愤愤道：金无望是什么东西，投靠了快活王做狗就了不起？\n",
	})	);  

	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",10);
}


int universe_busy(object *all_enm)
{
	int i,*busy_object;
	string e_name,e_name1;

	

//	delete("busy_object");
	command("exert douhanjue");

	if(!query_busy())
		return 0;
	return 1;
}


int normal_att(object opp)
{
	if(random(100)<50) return 0;
	set("force_factor",30);
	SKILL_D("dragonstrike")->perform_target(this_object(),"xianglongwuhui",opp);

	return 1;
}


int alert_att(object opp)
{
	if(random(100)<30) return 0;	
	set("force_factor",60);
	SKILL_D("dragonstrike")->perform_target(this_object(),"xianglongwuhui",opp);

	return 1;
}


int flee_att(object opp)
{
	if(random(100)<20) return 0;	
	set("force_factor",240);
	SKILL_D("doggiesteps")->perform_target(this_object(),"goujitiaoqiang",opp);
	return 1;
}
