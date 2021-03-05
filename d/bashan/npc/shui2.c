inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight(object who);

void create()
{
	object armor,weapon;
	set_name("水如昔", ({ "shui ruxi","shui"}) );
	set("gender", "女性" );
	set("title",YEL"大光明教 "NOR CYN"乾达婆王"NOR);
	set("nickname",HIW"梦里花落"NOR);
	set("age", 20+random(10));

	set("attitude","friendly");
	set("long",
		"\n"
		);

	set("resistance/kee",100);
	set("resistance/gin",100);
	set("resistance/sen",100);

	set("class","demon");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",20);
	set("per",200);
	set("force",2500);
	set("max_force",2500);
	set("force_factor",130+random(100));
	set("atman",1500);
	set("max_atman",1500);
	set("mana",1500);
	set("max_mana",1500);

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);


	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);
	
	set_skill("heavendance",220);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("stormdance",235);
	set_skill("move",200);
	set_skill("dodge",200);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 700);
	set_skill("force", 200);

	set_skill("lingxi-zhi", 170);
	set_skill("divineforce", 200);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	set_skill("dodge",200);

	set("NO_KILL",WHT"你的招式甫近水如昔，就为天都水月上散出的一层微光所阻。\n"NOR);

	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "divineforce");
	map_skill("dodge","stormdance");
	map_skill("move","stormdance");
	map_skill("blade","heavendance");
	map_skill("parry","heavendance");
    	

	add_temp("apply/iron-cloth", 200);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: smart_fight(this_object()) :),
	}) );

	setup();

	carry_object("/d/wudang/npc/obj/longskirt")->wear();
	carry_object("/d/wudang/npc/obj/cyin")->wield();
	carry_object(__DIR__"obj/stone")->wear();

/*
    set("reward_npc", 1);
	set("difficulty",7);
*/
}


int fight_ob(object who)
{
	who->remove_enemy(this_object());
	::fight_ob(who);
	return 1;
}

int kill_ob(object who)
{
	object me;
	int exp_r,busyst;
	string msg;
	if (who->is_zombie() == 1)
	{
		msg = HIW "$N扬了扬手，空气中点点星光闪烁，刹那间四周万籁俱寂．．．\n" NOR;
		message_vision(msg,this_object());
		who->die();
		return 1;
	}
	who->remove_killer(this_object());
	::kill_ob(who);
	return 1;
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
	return enemy[random(sizeof(enemy))];
}


void force_busy(int busy)
{
	message_vision(CYN"\n水如昔衣裙飘飞，已退在三丈之外。\n"NOR, this_object());
	return;
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	message_vision(CYN"\n水如昔衣裙飘飞，已退在三丈之外。\n"NOR, this_object());
	return;
}


void smart_fight(object who)
{
	object me,target,item;
	object * tar;
	object shadow,hisweapon,newweapon;
	int i,j,temp,num,temp1,num1;

	me = this_object();

	if (who != me)
		target = who;
	else
		target = select_opponent();
	
	tar = me->query_enemy();
	for (i=0;i<sizeof(tar) ;i++ )
		tar[i]->remove_killer(me);

	if (sizeof(tar) > 1)
	{
		message_vision(WHT"\n$N一挥水袖，一道银白色的丝线飞激而出，向场中众人落去。\n"NOR,me);
		for (i=0;i<sizeof(tar) ; i++)
		{
			if (i != sizeof(tar)-1)
				target = tar[i+1];
			else
				target = tar[0];

			if (tar[i]->is_unconcious())	continue;

// 为了让parry busy生效(爆,太恶毒了),这里不使用mimic function....
			target->add_temp("no_check_pfm_win",1);
			j = tar[i]->query_busy();
			tar[i]->stop_busy();
			tar[i]->add("force_factor",query("force_factor")/2);
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK,WHT"银白色的丝线拂过$N"WHT"，$N"WHT"脚下一个不稳，身不由己的向$n"WHT"攻去！"NOR);
			tar[i]->add("force_factor",-query("force_factor")/2);
			target->add_temp("no_check_pfm_win",-1);
			tar[i]->start_busy(j);
		}
	}

	return;
}

void die()
{
	return;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
