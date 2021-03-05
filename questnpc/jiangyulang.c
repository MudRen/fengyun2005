#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("江玉郎", ({ "jiang yulang", "jiang" }) );
	set("gender", "男性" );
	set("nickname",HIR"小玉郎"NOR);
        set("title","别鹤庄     少庄主");
        set("quality","evil");
	set("age", 21);
	set("int", 25);
	set("per", 20);
	set("str", 30);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"这孩子生得眉目清秀，但却面黄肌瘦，像是发育不全的模样。一双眼睛四下张 
望，时而露出种得意的笑容。\n");
        set("force_factor", 35);
	set("max_force",3000);
	set("force",5000);
        set("combat_exp", 4000000);
        set("score", -16000);
        set("strategy","conservative");
        set("alert_rate",70);
        set("flee_rate",50);
        set("hunting",1);
        set_skill("unarmed", 250);
        set_skill("force", 280);
        set_skill("parry", 260);
        set_skill("literate", 130);
	set_skill("dodge", 250);
	set_skill("shadowsteps", 150);
	set_skill("demon-strike",400);
	set_skill("meihua-shou",150);
	map_skill("unarmed", "meihua-shou");
	map_skill("dodge","shadowsteps");
	set("chat_chance",2);
	set("chat_msg",	({
	"江玉郎突然一笑，低声道：江小鱼。。嘿嘿，旺你自封天下第一聪明人，不是中了我的计。\n",
	})	);  

	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/lihuading");
	add_money("gold",10);
}


	
int normal_busy(object opp)
{
	if(random(100)>90)
	{
		set("class","legend");
		map_skill("unarmed","meihua-shou");
		SKILL_D("meihua-shou")->perform_target(this_object(),"meihai",opp);
		map_skill("unarmed","demon-strike");
		delete("class");
	}
	return 1;
}

int normal_att(object opp)
{
	if(random(100)<50) return 0;

	set("force_factor",90);
	say("90\n");
	if(random(10)>5)
	{
		set("class","taoist");
		SKILL_D("qiankunstrike")->perform_target(this_object(),"niuzhuanqiankun",opp);
		delete("class");
	}
	else
	{
		set("class","swordsman");
		SKILL_D("shadowsteps")->perform_target(this_object(),"lianhuanjiao",opp);
		delete("class");
	}
	return 1;
}

int alert_busy(object opp)
{

	if(random(100)>50)
	{

		set("class","legend");
		map_skill("unarmed","meihua-shou");
		SKILL_D("meihua-shou")->perform_target(this_object(),"meihai",opp);
		map_skill("unarmed","qiankunstrike");
		delete("class");
	}
	return 1;
}

int alert_att(object opp)
{
	if(random(100)<30) return 0;	
	set("force_factor",130);
	say("130\n");
	if(random(10)>5)
	{
		set("class","taoist");
		SKILL_D("qiankunstrike")->perform_target(this_object(),"niuzhuanqiankun",opp);
		delete("class");
	}
	else
	{
		set("class","swordsman");
		SKILL_D("shadowsteps")->perform_target(this_object(),"lianhuanjiao",opp);
		delete("class");
	}
	return 1;
}

int flee_busy(object opp)
{
	if(random(100)>20)
	{
	if(present("needle box",this_player()))
	{
		message_vision("江玉郎阴笑一声，从怀中掏出一个黄澄澄的圆筒！！\n",this_player());
		command("shoot "+opp->get_id());
	}
		set("class","legend");
		map_skill("unarmed","meihua-shou");
		SKILL_D("meihua-shou")->perform_target(this_object(),"meihai",opp);
		map_skill("unarmed","qiankunstrike");
		delete("class");
	}
	return 1;
}

int flee_att(object opp)
{

	say("150\n");
	set("force_factor",150);
	if(random(10)>5)
		{
			set("class","taoist");
			SKILL_D("qiankunstrike")->perform_target(this_object(),"niuzhuanqiankun",opp);
			delete("class");
		}
		else
		{
			set("class","swordsman");
			SKILL_D("shadowsteps")->perform_target(this_object(),"lianhuanjiao",opp);
			delete("class");
		}
	return 1;
}
