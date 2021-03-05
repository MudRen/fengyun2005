#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
do_fight();
void create()
{
	set_name("吕凤先", ({ "lv fengxian","lv" }) );
	set("gender", "男性" );
        set("nickname",YEL"天下第五人"NOR);
        set("title","银戟      温侯");
        set("quality","good");
	set("age", 43);
	set("int", 29);
	set("per", 30);

	set("dur", 30);
	set("cor", 50);
	set("long",
"一个华衣高冠的男子，银戟插在背后，似乎天下的威风都被一人占尽。\n"
		);
        set("force_factor", 40);
        set("max_gin", 13000);
        set("max_kee", 14100);
        set("max_sen", 13000);
		set("max_force",2000);
		set("force",2000);

        set("combat_exp", 7400000);
        set("score", 1200);
        set("w_type","spear");
        set("strategy","brave");
        set("hunting",1);
        set_skill("unarmed", 280);

        set_skill("force", 470);
        set_skill("parry", 310);
        set_skill("literate", 180);
	set_skill("dodge", 240);
	set_skill("nine-moon-steps",280);
	set_skill("wolf-claw",290);
	set_skill("bloodystrike",200);
        set_skill("hawk-steps",180);
	set_skill("spear",250);
	set_skill("xuezhan-spear",200);
	set_skill("skyforce",250);
	map_skill("force","skyforce");
	map_skill("unarmed", "wolf-claw");
        map_skill("sword","feixian-sword");
        map_skill("force", "jingyiforce");
        map_skill("parry", "xuezhan-spear");
        map_skill("spear", "xuezhan-spear");
		map_skill("dodge","nine-moon-steps");
		set("chat_chance",1);
		set("chat_msg",	({
		"吕凤先笑了笑，笑容中也带着种逼人的傲气，缓缓道：世上只有少数几个人值得 
我等，小李探花就是其中之一。 \n"
		})	);  
 
	setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/s_spear")->wield();
}


int universe_busy(object *all_enm)
{
	int i,*busy_object;
	string e_name,e_name1;


	set("class","shenshui");
//	delete("busy_object");
	for(i=0;i<sizeof(all_enm);i++)
	{
		if(!objectp(all_enm[i])) continue;

		if(all_enm[i]->query_busy())
			continue;
			SKILL_D("nine-moon-steps")->perform_target(this_object(),"lianhuanbu",all_enm[i]);

		
	}
	
	delete("class");
	if(query_busy())
		stop_busy();
	return 1;
}
	
int normal_busy(object opp)
{
	if(random(100)>50)
	{
		set("class","lama");
		map_skill("unarmed","bloodystrike");
		command("unwield all");
		SKILL_D("bloodystrike")->perform_target(this_object(),"fofawubian",opp);
		command("wield all");
		map_skill("unarmed","wolf-claw");
		delete("class");
	}
	return 1;
}

int normal_att(object opp)
{
	if(random(100)<50) return 0;
	set("force_factor",70);
		
		set("class","fugui");
		map_skill("dodge","hawk-steps");
		map_skill("spear","xuezhan-spear");
		SKILL_D("xuezhan-spear")->perform_target(this_object(),"yutianbigao",opp);
		map_skill("dodge","nine-moon-steps");
	

	delete("class");
	return 1;
}

int alert_busy(object opp)
{

	if(random(100)>50)
	{
		set("class","lama");
		map_skill("unarmed","bloodystrike");
		command("unwield all");
		SKILL_D("bloodystrike")->perform_target(this_object(),"fofawubian",opp);
		command("wield all");
		map_skill("unarmed","wolf-claw");
		delete("class");
	}
	return 1;
}

int alert_att(object opp)
{
	if(random(100)<30) return 0;	
	set("force_factor",100);	
	set("class","fugui");
		map_skill("dodge","hawk-steps");
		map_skill("spear","xuezhan-spear");
		SKILL_D("xuezhan-spear")->perform_target(this_object(),"bafangfengyu",opp);
		map_skill("dodge","nine-moon-steps");
		delete_temp("timer/bafang");
	
	delete("class");
	return 1;
}

int flee_busy(object opp)
{
	if(random(100)>1)
	{
		set("class","lama");
		map_skill("unarmed","bloodystrike");
		command("unwield all");
		SKILL_D("bloodystrike")->perform_target(this_object(),"fofawubian",opp);
		command("wield all");
		map_skill("unarmed","wolf-claw");
		delete("class");
	}
	return 1;
}

int flee_att(object opp)
{
	if(random(100)<5) return 0;	
	set("force_factor",270);
	command("unwield all");
		set("class","wolfmount");
		map_skill("unarmed","wolf-claw");
		add_temp("apply/attack",600);
		add_temp("apply/damage",900);
		SKILL_D("wolf-claw")->perform_target(this_object(),"ningxie",opp);
		add_temp("apply/attack",-600);
		add_temp("apply/damage",-900);
	command("wield all");
	delete("class");
	return 1;
}


