// ; annie 6.28.03

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
	set("nickname",MAG"紫皓星辰"NOR);
	set("age", 20+random(10));
	set("long",
		"\n"
		);
	set("class","legend");
    set("combat_exp", 5200000);
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
	set("no_arrest",1);
		
	set("resistance/gin",40);
	set("resistance/kee",40);
	set("resistance/sen",40);

	set("max_kee",16000);
	set("max_gin",9000);
	set("max_sen",9000);
	
	set_skill("heavendance",250);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("move",200);
	set_skill("dodge",200);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 300);
	set_skill("force", 200);

	set_skill("lingxi-zhi", 170);
	set_skill("divineforce", 200);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	set_skill("dodge",200);


	
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "divineforce");
    	map_skill("dodge","fall-steps");
    	map_skill("move","anxiang-steps");
    	map_skill("blade","heavendance");
    	map_skill("parry","heavendance");
    	

		add_temp("apply/iron-cloth", 200);
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight(this_object()) :),
        }) );

	setup();
    armor=new("/obj/armor/cloth");
	armor->set_name("一尘不染的白衣",({"cloth"}) );
	armor->move(this_object());
	armor->wear();

	weapon = new(__DIR__"obj/cyin");
	weapon->move(this_object());
	weapon->wield();
//	set_temp("protectors", ({ weapon } ));	// absorb 75% normalhit

    set("reward_npc", 1);
	set("difficulty",7);

}

int kill_ob(object who)
{
	object me;
	int exp_r,busyst;
	::kill_ob(who);
	stop_busy();
	smart_fight(who);
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
	message_vision(CYN"\n一圈淡蓝色的光芒在水如昔身边浅浅晕开。\n"NOR, this_object());
	return;
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	message_vision(CYN"\n一圈淡蓝色的光芒在水如昔身边浅浅晕开。\n"NOR, this_object());
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
	
	ccommand("perform force.baocanshouque");

	tar = me->query_enemy();
	if (sizeof(tar) > 1)
	{
		message_vision(WHT"\n$N幽幽的叹道：倚多为胜，算什么英雄行径．．．\n$N一挥水袖，一道银白色的丝线飞激而出，向场中众人落去。\n"NOR,me);
		for (i=0;i<sizeof(tar) ; i++)
		{
			if (i != sizeof(tar)-1)
				target = tar[i+1];
			else
				target = tar[0];

			if (tar[i]->is_unconcious())	continue;

/*
		seteuid(getuid());
		if (!userp(tar[i])) {
			sscanf(file_name(tar[i]),"%s#%d",temp,num);
			shadow=new(temp);
		} else {
			shadow=new("/d/fy/npc/shadefigure");
			shadow->changeshape(tar[i]);
		}
		if(hisweapon=tar[i]->query_temp("weapon"))
		{
			sscanf(file_name(hisweapon),"%s#%d",temp1,num1);
			newweapon=new(temp1);
			newweapon->move(shadow);
			newweapon->wield();
		}	
		shadow->set("owner",me);
		shadow->set("possessed",me);
		shadow->move(environment(me));
		shadow->kill_ob(tar[i]);	
		COMBAT_D->do_attack(shadow,tar[i],TYPE_REGULAR,WHT"银白色的丝线拂过$N，$N脚下一个不稳，身不由己的向$n攻去！"NOR);
		if (tar[i]->query_temp("damaged_during_attack"))
			tar[i]->set_temp("last_damage_from",me);
		destruct(shadow);
*/
// NOTICE:  BUGGED : 银白色的丝线拂过侍卫，侍卫脚下一个不稳，身不由己的向上官侍卫攻去！
// LOAD_NPC之后再进行处理的，包括GUARD,FIGHTER都会出错。

			j = tar[i]->query_busy();
			tar[i]->stop_busy();
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK,WHT"银白色的丝线拂过$N，$N脚下一个不稳，身不由己的向$n攻去！"NOR);
			tar[i]->start_busy(j+random(2));	// busy 0~1.
		}
	}

	target = select_opponent();
	if (!target->query_temp("annie/chillingheart") && target->query("kee") > 0)
	{
		target->set_temp("annie/chillingheart",1);
		message_vision(WHT"\n$N"WHT"收式后避，左手虚按胸前，凝望着$n"WHT"。\n"HIW"$n"HIW"看进$N"HIW"清澈而幽深的眼里，突觉得有沁骨冰风吹过，心口阵阵发凉。\n"NOR,me,target);
		target->receive_damage("kee",target->query("combat_exp") / 7500, me);
		call_out("do_chilling",3,me,target,5+random(5));
	}
	return;
}

void do_chilling(object me,object target,int count)
{
	if (!target)	// 离开战斗后同样发作。频率比正常condition快，不可解除。
		return ;
	if (!me)
	{
		target->set_temp("annie/chillingheart",0);
		tell_object(target,HIW"你中的「"HIC"千冰冻魄"HIW"」终于发作空了。\n"NOR);
		return;
	}
	if (count > 0)
	{
		count = count - 1;
		tell_object(target,HIW"你中的「"HIC"千冰冻魄"HIW"」发作了！\n一丝一缕的寒气透进你的心里．．．\n"NOR);
		target->receive_damage("kee",target->query("combat_exp") / 7500, me);
		call_out("do_chilling",3,me,target,count);
	}
	else
	{
		target->set_temp("annie/chillingheart",0);
		tell_object(target,HIW"你中的「"HIC"千冰冻魄"HIW"」终于发作空了。\n"NOR);
	}
	return;
}


// update here;clone /d/mingyue/npc/du;call du->set("busy_type",1);call du->set("enemy_id","master");call du->ccommand("kill master")
// clone /d/mingyue/npc/phoenix;clone /d/mingyue/npc/tiger;clone /d/mingyue/npc/dragon;clone /d/mingyue/npc/turtle
// call master->ccommand("kill phoenix");call master->ccommand("kill tiger");call master->ccommand("kill turtle");call master->ccommand("kill dragon");

