#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("李燕北", ({ "li yanbei", "li" }) );
	set("gender", "男性" );
	set("nickname",HIC"仁义满京华"NOR);
        set("title","威镇京城     北豪");
        set("quality","good");
	set("age", 43);
	set("int", 21);
	set("per", 20);
	set("str", 40);
	set("dur", 50);
	set("cor", 35);
	set("long",
"李燕北身高八尺—寸，魁伟强壮，精力充沛，浓眉、锐眼、鹰鼻、严肃的脸上，
总是带著种接近残酷的表情，看来就像是条刚从原始山林中窜出来的豹子。\n");
        set("force_factor", 30);
        set("max_gin", 9400);
        set("max_kee", 13200);
        set("max_sen", 8700);
		set("max_force",2000);
		set("force",2000);
	set("strategy","brave");
	set("hunting",1);
	set("w_type", "blade");
        set("combat_exp", 5500000);
        set("score", 15000);
        set_skill("unarmed", 450);
        set_skill("force", 120);
        set_skill("parry", 140);
        set_skill("literate", 150);
	set_skill("dodge", 140);
//	set_skill("tang-blade",150);
	set_skill("wind-blade",200);
	set_skill("blade",240);
	set_skill("fire-strike",150);
	set_skill("meng-steps",200);
//	map_skill("blade","tang-blade");
	map_skill("parry","wind-blade");
	map_skill("unarmed","fire-strike");
	map_skill("dodge","meng-steps");
	
		
     
//        set("chat_chance_combat", 40);
//        set("chat_msg_combat", ({
//                (: perform_action,"spear.qingheluo":),
//        }) );
	setup();
	carry_object(__DIR__"obj/zimagua")->wear();
	carry_object("obj/weapon/blade")->wield();
	add_money("gold",8);
}
/*
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}


*/


int universe_busy(object *all_enm)
{
	int i,*busy_object;
	string e_name,e_name1;
	
	set("class","bat");
//	delete("busy_object");
	for(i=0;i<sizeof(all_enm);i++)
	{
		if(!objectp(all_enm[i])) continue;
		add("busy_object/"+all_enm[i]->get_id(),1);
		if(all_enm[i]->query_busy())
			continue;
//		say("haha1\n");
		SKILL_D("meng-steps")->perform_target(this_object(),"huanyinqianchong",all_enm[i]);
	
	}
	
	delete("class");
	if(!query_busy())
		return 0;
	return 1;
}



int normal_att(object opp)
{
	if(random(100)<50) return 0;
	set("force_factor",50);
	SKILL_D("tang-blade")->perform_target(this_object(),"banlanwushi",opp);

	return 1;
}


int alert_att(object opp)
{
	if(random(100)<30) return 0;	
	set("force_factor",100);
	SKILL_D("tang-blade")->perform_target(this_object(),"banlanwushi",opp);

	return 1;
}


int flee_att(object opp)
{
	if(random(100)<20) return 0;	
	set("force_factor",150);
	SKILL_D("tang-blade")->perform_target(this_object(),"banlanwushi",opp);
	return 1;
}
