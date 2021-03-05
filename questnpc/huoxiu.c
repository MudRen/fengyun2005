#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("霍休", ({ "huo xiu", "huo" }) );
	set("gender", "男性" );
	set("nickname",HIR"富甲天下"NOR);
        set("title","青衣楼   总瓢把子");
        set("quality","evil");
	set("age", 67);
	set("int", 25);
	set("per", 20);
	set("str", 60);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"霍老头，矮小，孤独，干净，硬朗，看起来就像是枚风干了的硬壳果。\n");
        set("force_factor", 55);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 6000000);
        set("score", -6000);
        set_skill("unarmed", 250);
        set_skill("force", 280);
        set_skill("parry", 360);
        set_skill("literate", 130);
	set_skill("dodge", 250);
	set_skill("windy-steps",250);
	set_skill("doomsteps",150);
	set_skill("dabei-strike", 130);
	set_skill("doomstrike",250);
	map_skill("unarmed", "doomstrike");
	map_skill("dodge","windy-steps");
	set("strategy","conservative");
	set("hunting",1);
	set("chat_chance",2);
	set("chat_msg",	({
	"霍休撂着花白的胡子笑道：青衣一百零八楼总瓢把子，总瓢把子， \n哈哈，这声音真好听，我喜欢听这四个字。\n"
	})	);  

	setup();
	carry_object("/obj/armor/cloth")->wear();
	add_money("gold",5);
}

int universe_busy(object *all_enm)
{
	int i,*busy_object;
	string e_name,e_name1;

	
	set("class","knight");
//	delete("busy_object");
	for(i=0;i<sizeof(all_enm);i++)
	{
		if(!objectp(all_enm[i])) continue;
		add("busy_object/"+all_enm[i]->get_id(),1);
		if(all_enm[i]->query_busy())
			continue;
//		if(all_enm[i]->query("combat_exp")>5000000)
//			continue;
		SKILL_D("windy-steps")->perform_target(this_object(),"fengliu",all_enm[i]);

		
	}
	
	delete("class");
	if(!query_busy())
		return 0;
	return 1;
}
	
int normal_busy(object opp)
{
	if(random(100)>90)
	{
		set("class","shaolin");
		map_skill("unarmed","dabei-strike");
		SKILL_D("dabei-strike")->perform_target(this_object(),"qianshouqianbian",opp);
		map_skill("unarmed","doomstrike");
		delete("class");
	}
	return 1;
}

int normal_att(object opp)
{
	if(random(100)<50) return 0;
	set("force_factor",55);
	map_skill("dodge","doomsteps");
	SKILL_D("doomsteps")->perform_target(this_object(),"hantian",opp);
	map_skill("dodge","windy-steps");

	return 1;
}

int alert_busy(object opp)
{

	if(random(100)>50)
	{
		set("class","shaolin");
		map_skill("unarmed","dabei-strike");
		SKILL_D("dabei-strike")->perform_target(this_object(),"qianshouqianbian",opp);
		map_skill("unarmed","doomstrike");
		delete("class");
	}
	return 1;
}

int alert_att(object opp)
{
	if(random(100)<30) return 0;	
	set("force_factor",90);	
	map_skill("dodge","doomsteps");

	SKILL_D("doomsteps")->perform_target(this_object(),"hantian",opp);
	map_skill("dodge","windy-steps");

	return 1;
}

int flee_busy(object opp)
{
	if(random(100)>20)
	{
		set("class","shaolin");
		map_skill("unarmed","dabei-strike");
		SKILL_D("dabei-strike")->perform_target(this_object(),"qianshouqianbian",opp);
		map_skill("unarmed","doomstrike");
		delete("class");
	}
	return 1;
}

int flee_att(object opp)
{
	if(random(100)<20) return 0;	
	set("force_factor",120);
	map_skill("dodge","doomsteps");
	add("apply/attack",150);
	SKILL_D("doomsteps")->perform_target(this_object(),"hantian",opp);
	add("apply/attack",-150);
	map_skill("dodge","windy-steps");
	return 1;
}


