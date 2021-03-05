#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
do_fight();
void create()
{
	set_name("林诗音", ({ "lin shiyin","lin" }) );
	set("gender", "女性" );
        set("nickname",GRN"往事不可追"NOR);
        set("title","兴云庄   庄主夫人");
        set("quality","good");
	set("age", 28);
	set("int", 29);
	set("per", 50);
	set("str", 12);
	set("dur", 30);
	set("cor", 50);
	set("long",
"林诗音并不能算是个真正完美无瑕的女人，但谁也不能否认她是个美人，她的脸 
色太苍白，身子太单薄，她的眼睛虽明亮，也嫌太冷漠了些，可是她的风韵，她 
的气质，却是无可比拟的。无论在任何情况下，她都能使人感觉到她那种独特的 
魅力，无论谁只要瞧过她一眼，就永远无法忘记。\n"
		);
        set("force_factor", 140);
        set("max_gin", 13000);
        set("max_kee", 14100);
        set("max_sen", 13000);
		set("max_force",2000);
		set("force",2000);
	set("strategy","conservative");
	set("hunting",1);
        set("combat_exp", 3700000);
        set("score", 1200);
        set("w_type","sword");
        
        set_skill("unarmed", 180);
        set_skill("sword", 110);
        set_skill("force", 170);
        set_skill("parry", 190);
        set_skill("literate", 80);
	set_skill("dodge", 140);

        set_skill("siqi-sword", 180);
	set_skill("xianjing", 60);
        set_skill("liuquan-steps",180);
        set_skill("yunwu-strike",180);
	set_skill("iron-cloth",200);
	set_skill("spring-water",200);
	map_skill("iron-cloth","spring-water");	
//	map_skill("unarmed", "meihua-shou");
        map_skill("sword","siqi-sword");
        map_skill("force", "xianjing");
        map_skill("parry", "siqi-sword");
        map_skill("unarmed", "yunwu-strike");
		map_skill("dodge","liuquan-steps");
		set("chat_chance",1);
		set("chat_msg",	({
		"林诗音似乎已麻木，呆呆地看着云起云灭，花开花落。\n"
		})	);  

	setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

int universe_busy(object *all_enm)
{
	int i,*busy_object;
	string e_name,e_name1;

	
	set("class","huangshan");
//	delete("busy_object");
	if(!query_temp("daoqian"));
	SKILL_D("spring-water")->perform_target(this_object(),"bingwantianzhang",this_object());
	stop_busy(); 
	for(i=0;i<sizeof(all_enm);i++)
	{
		if(!objectp(all_enm[i])) continue;
		add("busy_object/"+all_enm[i]->get_id(),1);
		if(all_enm[i]->query_busy())
			continue;

		SKILL_D("liuquan-steps")->perform_target(this_object(),"liushuichanchan",all_enm[i]);

		
	}
	
	delete("class");
	if(!query_busy())
		return 0;
	return 1;
}
	
int normal_busy(object opp)
{
	if(random(100)>50)
	{
		set("class","huangshan");
		command("unwield all");
		SKILL_D("yunwu-strike")->perform_target(this_object(),"miwu",opp);
		command("wield all");
		delete("class");
	}
	return 1;
}

int normal_att(object opp)
{
	if(random(100)<50) return 0;
	set("force_factor",140);
	set("class","huangshan");
	SKILL_D("siqi-sword")->perform_target(this_object(),"siqi",opp);
	delete("class");
	return 1;
}

int alert_busy(object opp)
{

	if(random(100)>50)
	{
		set("class","huangshan");
		command("unwield all");
		SKILL_D("yunwu-strike")->perform_target(this_object(),"miwu",opp);
		command("wield all");
		delete("class");
	}
	return 1;
}

int alert_att(object opp)
{
	if(random(100)<30) return 0;	
	set("force_factor",240);
	set("class","huangshan");
	SKILL_D("siqi-sword")->perform_target(this_object(),"siqi",opp);
	delete("class");
	return 1;
}

int flee_busy(object opp)
{
	if(random(100)>20)
	{
		set("class","huangshan");
		command("unwield all");
		SKILL_D("yunwu-strike")->perform_target(this_object(),"miwu",opp);
		command("wield all");
		delete("class");
	}
	return 1;
}

int flee_att(object opp)
{
	if(random(100)<20) return 0;	
	set("force_factor",340);
	set("class","huangshan");
	SKILL_D("siqi-sword")->perform_target(this_object(),"siqi",opp);
	delete("class");
	return 1;
}

int die_action()
{
	object me,target;
	string msg;
	
	me=this_object();
	target=me->query_temp("last_damage_from");
	if(!objectp(target)||environment(target)!=environment())
		return 0;
	
	 msg = RED"$N含泪道：“恶贼！我要与你同归于尽！”说完狂喷鲜血，瞬时间天地为之变色！\n";
    if(me->query("combat_exp") > random(target->query("combat_exp")) )
    {
        msg += "慢慢地，$n被一片红色的血雾包围，什么都看不见了！\n"NOR;
        //target->receive_damage("kee",(int)me->query("max_kee")+1,me);
        //receive_wound("kee", ((int)me->query("max_kee")+5000),me);
        message_vision(msg, me, target);
        target->die();

    }
    else
    {
        msg += "可是$n还是躲过了$N的最后一击！！" NOR;
        message_vision(msg, me, target);

        me->unconcious();
    }
	return 0;
}