
inherit QUESTNPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("路小佳", ({ "lu xiaojia", "lu" }) );
	set("gender", "男性" );
        set("age", 25);
        set("title", "独行刺客     电剑" );
        set("nickname", HIR"快意江湖"NOR );
        set("quality","evil");
	set("int", 35);
	set("per", 30);
	set("long",
"他是个年轻人，一个奇怪的年轻人，有着双奇怪的眼睛，就连笑的时候，这双
眼睛都是冷冰的，就像是死人的眼睛，没有情感，也没有表情。
\n"
		);
        set("max_force", 4000);
        set("force", 4000);
	set("force_factor", 100);
	set("cor",80);
	set("str",50);
        set("combat_exp", 8000000);
        set("score", 3000);
        set("hunting",1);
        set("w_type","sword");
        set_skill("unarmed",120);
        set_skill("flame-strike",120);
        
        set_skill("sword", 150);
        set_skill("force", 170);
        set_skill("parry", 180);
        set_skill("literate", 90);
	set_skill("dodge", 190);
        set("agi",25);
        set("int",30);
		set("chat_chance",10);
		set("chat_msg",({
"路小佳拈起一颗花生，剥开，抛起，然后看着这颗花生落到自己嘴里，闭上眼睛，
长长的叹了口气，开始慢慢咀嚼。\n",
"路小佳忽然笑笑 ，说道：“杀人是件干净痛快的事情。”他顿了一顿，又说道：
“所以在杀人之前，我一定要洗个澡。”\n",
		})	);
	set_skill("hawk-steps",200);
	set_skill("lefthand-sword", 150);
	set_skill("softsword",190);
	set_skill("three-sword",150);
	set_skill("diesword",140);
	set_skill("taiji-sword",170);
	set_skill("taijiforce",100);
        map_skill("sword", "diesword");
        map_skill("parry","diesword");
        map_skill("dodge","hawk-steps");
        map_skill("unarmed","flame-strike");
        map_skill("force","taijiforce");
	setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/lusword")->wield();
}



int universe_busy(object *all_enm)
{
	int i,*busy_object;
	string e_name,e_name1;

	
	set("class","fugui");
//	delete("busy_object");
	for(i=0;i<sizeof(all_enm);i++)
	{
		if(!objectp(all_enm[i])) continue;

		if(all_enm[i]->query_busy())
			continue;
			SKILL_D("hawk-steps")->perform_target(this_object(),"yingjichangkong",all_enm[i]);

		
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
		set("class","wudang");
		map_skill("sword","three-sword");
		SKILL_D("three-sword")->perform_target(this_object(),"nianzijue",opp);
		map_skill("sword","diesword");
		delete("class");
	}
	return 1;
}

int normal_att(object opp)
{
	if(random(100)<50) return 0;
	set("force_factor",70);
	if(random(10)<5)
	{
		set("class","assassin");
		map_skill("sword","lefthand-sword");
		SKILL_D("lefthand-sword")->perform_target(this_object(),"duxin",opp);
		map_skill("sword","diesword");
	}
	else
	{
		set("class","swordsman");
		map_skill("sword","softsword");
		SKILL_D("softsword")->perform_target(this_object(),"changtianluodian",opp);
		map_skill("sword","diesword");		
	}
	delete("class");
	return 1;
}

int alert_busy(object opp)
{

	if(random(100)>50)
	{
		set("class","wudang");
		map_skill("sword","three-sword");
		SKILL_D("three-sword")->perform_target(this_object(),"nianzijue",opp);
		map_skill("sword","diesword");
		delete("class");
	}
	return 1;
}

int alert_att(object opp)
{
	if(random(100)<30) return 0;	
	set("force_factor",100);	
	if(random(12)<8)
	{
		set("class","assassin");
		map_skill("sword","lefthand-sword");
		SKILL_D("lefthand-sword")->perform_target(this_object(),"duxin",opp);
		map_skill("sword","diesword");
	}
	else
	{
		set("class","swordsman");
		map_skill("sword","softsword");
		SKILL_D("softsword")->perform_target(this_object(),"changtianluodian",opp);
		map_skill("sword","diesword");		
	}
	delete("class");
	return 1;
}

int flee_busy(object opp)
{
	if(random(100)>20)
	{
		set("class","wudang");
		map_skill("sword","taiji-sword");
		SKILL_D("taiji-sword")->perform_target(this_object(),"nianzijue",opp);
		map_skill("sword","diesword");
		delete("class");
	}
	return 1;
}

int flee_att(object opp)
{
	if(random(100)<5) return 0;	
	set("force_factor",200);
	if(random(10)<5)
	{
		set("class","legend");
		map_skill("sword","diesword");
		opp->start_busy(1);
		SKILL_D("diesword")->perform_target(this_object(),"caidiekuangwu",opp);
		opp->stop_busy();

	}
	else
	{
		set("class","swordsman");
		map_skill("sword","softsword");
		opp->start_busy(1);
		SKILL_D("softsword")->perform_target(this_object(),"muyufeihong",opp);
		opp->stop_busy();
		map_skill("sword","diesword");		
	}
	delete("class");
	return 1;
}


