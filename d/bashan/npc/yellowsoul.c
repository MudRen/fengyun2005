// 雌剑魂 使用非物理伤害KEE DAMAGE杀。

#include <ansi.h>
inherit NPC;
void smart_fight();
void leave();
void create()
{
	object weapon;
    set_name(YEL"剑魂·雌"NOR, ({ "sword spirit", "spirit","sword spirit yellow" }) );
    set("race", "昆虫");
    set("age", 1);
    set("gender", "雌性");
    set("long", "经历了千年风霜，无数附生在古剑·莫邪上的精魂之英。\n");
    set("attitude","peaceful");
    set("limbs", ({ "剑柄", "剑身","剑穗", "剑刃" }) );
    set("verbs", ({ "insect-kick"}) );
	set("weight", 300);
	set("str",90);
	set("force_factor",0);
	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);


	set("max_kee", 2000);
	set("eff_kee", 2000);
	set("kee", 2000);

	set("resistance/gin",100);
	set("resistance/sen",100);

	set("max_mana",500000);
	set("mana",500000);

//	set_temp("till_death/shield_lock",1);
	set_temp("shield_force/type","mana");
	set_temp("shield_force/ratio",10000);
	set_temp("shield_force/msg",
		MAG"$N"MAG"招式甫及$n"MAG"身前三尺之外，便如泥牛入海，消失在紫气中。\n"NOR);

	set_skill("qiuzhi-sword",200);
	set_skill("sword",200);
	map_skill("sword","qiuzhi-sword");

	set("combat_exp", 10000000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
               (: smart_fight() :),
    }));

	set("chat_chance", 100);
    set("chat_msg", ({
               (: leave() :),
    }));

    setup();

	weapon = new("/obj/weapon/sword");
	weapon->set_name(YEL"剑芒"NOR, ({ "ghosty aura","sword" }));
	weapon->set("value",0);
	weapon->set("unit","把");
	weapon->set("nodrop_weapon",1);
	weapon->set("long","一丝虚无飘渺的魂魄．．．\n");
	weapon->move(this_object());
	weapon->set("equipped","wielded");
	set_temp("weapon",weapon);
	set_temp("apply/none",1);	// to prevent destruct failed.

}

void dismiss_team()
{
	// to prevent destruct failed.
	object weapon = present("ghosty aura",this_object());
	if (weapon)
	{
	weapon->delete("equipped");
	delete_temp("weapon");
	}
	::dismiss_team();
	return;
}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[0];	// 从0杀起
}


void smart_fight()
{
	object target=select_opponent();
	SKILL_D("qiuzhi-sword")->perform_target(this_object(),"hanmeiluo",target);
}


void unconcious()
{
	die();
}

void die()
{
	object owner,*pros;
	message("vision",HIY"剑魂·雌化为一道黄气，飞快地流进楚南江手中的古剑·莫邪。\n" NOR, environment(),this_object() );
	if(objectp(owner=this_object()->query("possessed")))
	{
		pros = owner->query_temp("protectors");
		pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
		owner->set("yellow",time());
	}                
	destruct(this_object());

}

void leave()
{
	object owner,*pros;
	message("vision",HIY"剑魂·雌化为一道黄气，飞快地流进楚南江手中的古剑·莫邪。\n" NOR, environment(),this_object() );
	if(objectp(owner=this_object()->query("possessed")))
	{
		pros = owner->query_temp("protectors");
		pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
	}                
	destruct(this_object());

}

void init()
{
	::init();
	add_action("do_look","look");
}

int do_look(string arg)
{
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
write(YEL"经历了千年风霜，无数附生在古剑·莫邪上的精魂之英。\n"NOR);
write("它看来十分机灵。\n");
write("武功看起来好象"HIR"深不可测"NOR"，出手似乎很重。\n");
	return 1;
}
/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
