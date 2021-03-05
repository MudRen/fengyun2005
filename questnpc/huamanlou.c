#include <ansi.h>
inherit QUESTNPC;
void create()
{
        set_name("花满楼", ({ "hua manlou","hua" }) );
        set("gender", "男性");
        set("age", 32);
        set("nickname",WHT"鲜花满楼"NOR);
        set("title","江南花家     七倌");
        set("quality","good");
        set("long",
"鲜花满楼。花满楼对鲜花总是有种强烈的热爱，正如他热爱所有的生命一样。
\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 8000000);
        set("chat_chance", 10);
        set("chat_msg", ({
"花满楼说道：只要你肯去领略，就会发现人生本是多么可爱，每个季节里都有
很多足以让你忘记所有烦恼的赏心乐事。\n",
"花满楼沉着的面庞突然一歪：陆小凤那小子已经失踪了好些日子了，究竟去哪了？\n", 
"花满楼道：我有很充足的睡眠，有很好的胃口，有这间很舒服的屋子，有一把
声音很好的古琴，这些本已足够，何况我还有个很好的朋友。\n",
        }) );
		set("chat_chance_combat",40);
		set("chat_msg_combat", ({
			(:perform_action,"unarmed.xinyoulingxi":)
		})	);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 90);
        set("fle",30);
	set("int",41);
	set("cor",40);
	set("per",40);
        set_skill("force", 80);
        set_skill("unarmed", 200);
        set_skill("dodge", 220);
	set_skill("parry",220);
	set_skill("lingxi-zhi",350);
	set_skill("move", 220);
	set_skill("fall-steps",100);
	map_skill("unarmed","lingxi-zhi");
	map_skill("move","fall-steps");
	map_skill("dodge","fall-steps");
	set("strategy","brave");
	set("hunting",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

int universe_busy(object *all_enm)
{
	command("perform xinyoulingxi");
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int myexp,hisexp;
	myexp=me->query("combat_exp");
	hisexp=victim->query("combat_exp");

	if (random(myexp+hisexp)>hisexp&&(!random(2)))
	{
		victim->start_busy(10+random(10));
//		victim->remove_all_killer();
        return HIR "$n只觉得一麻，要穴被制，一动都不能动了。\n" NOR;
	}
}

int kill_ob(object enemy)
{
	if(enemy->query_busy())
	{
		message_vision(HIC"花满楼微笑的对$N道：“阁下已无还手之力，乘人之危的事，非君子之道。”\n"NOR,enemy);
		return 0;
	}
	::kill_ob(enemy);
}

int normal_att(object opp)
{
	set("force_factor",50);
	return 1;
}


int alert_att(object opp)
{
	set("force_factor",90);
	return 1;
}


int flee_att(object opp)
{
	set("force_factor",200);
	return 1;
}