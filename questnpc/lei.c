#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
do_fight();
void create()
{
	set_name("小雷", ({ "xiao lei","lei" }) );
	set("gender", "男性" );
        set("nickname",RED"我要活下去"NOR);
        set("title","风雷山庄     少侠");
        set("quality","good");
	set("age", 23);
	set("int", 29);
	set("per", 30);
	set("str", 52);
	set("dur", 30);
	set("cor", 50);
	set("long",
"他脸上流着血，流着汗，全身的骨骼都似已将因痛苦而崩散。\n"
		);
        set("force_factor", 40);
        set("max_gin", 9000);
        set("max_kee", 14100);
        set("max_sen", 9000);
		set("max_force",2000);
		set("force",2000);
	set("hunting",1);
	set("strategy","brave");
	set("w_type","sword");
        set("combat_exp", 4700000);
        set("score", 1200);
        set_skill("unarmed", 80);
        set_skill("sword", 370);
        set_skill("force", 170);
        set_skill("parry", 310);
        set_skill("literate", 80);
	set_skill("dodge", 310);
	set_skill("xiaohun-sword",150);
        set_skill("feixian-sword", 150);
        set_skill("sharen-sword",200);
	set_skill("yiqiforce", 60);
        set_skill("feixian-steps",150);
	
//	map_skill("unarmed", "meihua-shou");
        map_skill("sword","feixian-sword");
        map_skill("force", "yiqiforce");
        map_skill("parry", "xiaohun-sword");
		map_skill("dodge","feixian-steps");
		set("chat_chance",10);
		set("chat_msg",	({
		"小雷咬紧牙关道“因为我还活着，一个人只要还活着，就得活下去。”\n"
		})	);  

	setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

int normal_att(object opp)
{
	if(random(100)<50) return 0;
	set("force_factor",60);
	SKILL_D("feixian-steps")->perform_target(this_object(),"tianwaifeixian",opp);

	return 1;
}


int alert_att(object opp)
{
	if(random(100)<30) return 0;	
	set("force_factor",100);
	SKILL_D("feixian-steps")->perform_target(this_object(),"tianwaifeixian",opp);

	return 1;
}


int flee_att(object opp)
{
	int extra;
	
	if(random(100)<20) return 0;	
	set("force_factor",140);
	map_skill("sword","sharen-sword");
	extra=100+random(100);
	add("apply/attack",extra);
	SKILL_D("sharen-sword")->perform_target(this_object(),"sharenruma");
	add("apply/attack",-extra);
	map_skill("sword","feixian-sword");
	return 1;
}
