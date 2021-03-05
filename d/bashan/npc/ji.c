inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
	object armor,weapon;
	set_name("季南风", ({ "ji nanfeng","nanfeng","ji"}) );
	set("gender", "男性");
	set("title",CYN"血雨门 "NOR MAG"天虹刺客"NOR);
	set("nickname", BBLU HIW"风雷剑神"NOR);
	set("age", 20+random(10));
	set("long","他身在血雨门下，却从不受人驱使，行为间我行我素，\n血雨门门主虽然心有不甘，却也无法奈何。\n");
    set("combat_exp", 8000000);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",40);
	set("force_factor",150);
	set("per",40);

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);

	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set_skill("demon-blade",240);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",340);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("move",200);
	set_skill("dodge",200);

	set_skill("demon-force",200);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 300);
	set_skill("force", 200);

	set_skill("lingxi-zhi", 170);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	set_skill("dodge",200);
	set_skill("divineforce",200);	

	set_skill("qiuzhi-sword",250);
	set_skill("daimonsword",250);
	set_skill("zensword",250);
	set_skill("sword",200);

	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "divineforce");
	map_skill("dodge","cloud-dance");
	map_skill("move","anxiang-steps");
	map_skill("sword","daimonsword");
	map_skill("parry","qiuzhi-sword");
	
    	
        add_temp("apply/iron-cloth", 200);
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

	setup();

	carry_object(__DIR__"obj/chusword4")->wield();

    armor=new("/obj/armor/cloth");
	armor->set_name("宽大的半旧长袍",({"cloth"}) );
	armor->move(this_object());
	armor->wear();

    set("reward_npc", 1);
	set("difficulty",7);
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

void attackx(object me,object target,int attack,int damage)
{
	me->add_temp("apply/attack",attack);
	me->add_temp("apply/damage",damage);
	target->add_temp("combat_no_report",1);
	COMBAT_D->do_attack(me,target,TYPE_PERFORM," ");
	target->add_temp("combat_no_report",-1);
	if (!target->query_temp("damaged_during_attack"))
		message_vision("结果没有对$N造成任何伤害。\n\n",target);
	else
		COMBAT_D->report_status(target);

	me->add_temp("apply/attack",-attack);
	me->add_temp("apply/damage",-damage);
}

int kill_ob(object who)
{
	int a = query_busy();

	if (base_name(who) == "/obj/npc/danei" || base_name(who) == "/obj/npc/danei_guard")
	{
		message_vision(HIW "$N扬了扬手，空气中点点星光闪烁，刹那间四周万籁俱寂．．．\n" NOR,this_object());
		who->die();
		return 1;
	}

	::kill_ob(who);
	smart_fight();
	return 1;
}

int bbqthem(object me, object obj) 
{
	int spells, busy_num,mod,magic;
	string id_enemy;
	mapping buff;
	

	if (ANNIE_D->check_buff(obj,"blind")) return 1;

	buff =
	([
		"caster":me,
		"who":obj,
		"type":"blind",
		"att":"curse",
		"name":"风雷剑客·无日剑式",
		"buff1":"block_msg/all",
		"buff1_c":1,
		"time":10,
		"buff_msg":YEL"一道耀眼的亮光闪过，$N"YEL"只觉得眼前白茫茫的一片，什么都看不到了．．．\n"NOR,
		"disa_msg":HIG"慢慢慢慢的，你的眼睛开始可以分辨周围的事物了。\n"NOR,
	]);
	ANNIE_D->buffup(buff);

	return 1;
}

void smart_fight()
{
	int i,n=99,resist;
	object *enemy,me=this_object();
	string action;
	object env, *inv;

	env = environment(me);
	inv = all_inventory(env);
	enemy = me->query_enemy();

	if (is_busy())
		return;

	i = random(6);
	switch (i)
	{
	case 0:
		message_vision(BBLU HIW"\n季南风施展"BRED HIW"无日剑式"NOR BBLU HIW"！\n"NOR,this_object());
		attackx(me, enemy[random(sizeof(enemy))], 150, 999);
		if (sizeof(enemy))
	        for(i=0; i<sizeof(enemy); i++)
				bbqthem(me, enemy[i]);
		perform_busy(3);
		break;
	case 1:
		message_vision(BBLU HIW"\n季南风施展"BRED HIW"神剑傲洲"NOR BBLU HIW"！\n"NOR,this_object());

		if (sizeof(enemy))
	        for(i=0; i<sizeof(enemy); i++)
				attackx(me, enemy[i], 300, 300);

		perform_busy(3);
		break;
	case 2:
		message_vision(BBLU HIW"\n季南风施展"BRED HIW"奔雷闪袭"NOR BBLU HIW"！\n"NOR,this_object());
		if (sizeof(enemy))
	        for(i=0; i<sizeof(enemy); i++)
			{
				attackx(me, enemy[i], 600, -300);
				if (enemy[i]->query_temp("damaged_during_attack"))
				{
					message_vision(YEL"$N"YEL"一着此式，顿时如遭雷殛，浑身麻软。\n"NOR,enemy[i]);
					enemy[i]->perform_busy(enemy[i]->query_busy()+3+random(3));
				}
			}
		perform_busy(3);
		break;
	case 3:
		message_vision(BBLU HIW"\n季南风施展"BRED HIW"睨睥如何"NOR BBLU HIW"！\n"NOR,this_object());
		n=sizeof(enemy);
		if (n>5)
			n = 5;
		if (sizeof(enemy))
	        for(i=0; i<n*2; i++)
				attackx(me, enemy[random(sizeof(enemy))], 150, 200);

		perform_busy(3);
		break;
	case 4:
		message_vision(BBLU HIW"\n季南风施展"BRED HIW"狂橫长沙"NOR BBLU HIW"！\n"NOR,this_object());

		if (sizeof(enemy))
	        for(i=0; i<sizeof(enemy); i++)
			{
				resist=me->query_temp("resistance/kee");
				if (resist > 0 )
					me->set_temp("resistance/kee",0);
				attackx(me, enemy[i], 0, 500);
				me->set_temp("resistance/kee",resist);
			}

		perform_busy(3);
		break;
	case 5:
		message_vision(BBLU HIW"\n季南风施展"BRED HIW"绝罢天地"NOR BBLU HIW"！\n"NOR,this_object());
		attackx(me, enemy[random(sizeof(enemy))], 888, 2222);
		perform_busy(2);
		break;
	}

	return;
}


void die()
{
	object me=this_object(),owner,enemy,paper,*sy_inv,things,env=environment(me),soul;
	int j;
	if (!query_temp("last_damage_from"))
	{
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		delete("reward_npc");
		::die();
		return;
	}
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
			enemy = owner;
	::die();
	return;
}

	
mapping ob_hit(object attacker, object victim,int damage)
{
	mapping data = ([]);
	if (!victim->query_busy())
		return 0;
	victim->stop_busy();
	data["msg"] = CYN"$n白袍鼓动，借$N一击之力向后轻飘飘的退了开去。\n"NOR;
	return data;
}

/*
update here;ask ke about silencer;call mingyue->delete_temp(inquiry_time);ask ke about silencer;updatep /d/bashan/npc/;clone /d/bashan/npc/chu;call chu->ccommand(kill fighter);call chu->ccommand(kill fighter 2);
update here;clone /d/bashan/npc/yawnboy;clone /d/bashan/npc/yawngirl;updatep /d/bashan/npc/;clone /d/bashan/npc/chu;call chu->ccommand(kill justdoit);call chu->ccommand(kill sinny);

也不妨潜心武学。可以将师父的毕生心血，发扬光大，可以令自己的惊才绝艳，有所寄托。
练吧！练吧！师父留下的终究有限，能弥补的也都弥补了，那就再演化自己的心得，由剑向外，还有拳掌。
创吧！创吧！武学的三千弱水，一瓢一瓢下来，总能将自己的一点点冥顽淹没。

休去管它此岸的修行，能否得证彼岸的善果。西天的有无，原也不算得什么。
不过剑法之外还可以有掌法，那，佛法之外呢？

等你也站在我今天的位置上，就会明白，现在的我，再没有其他选择。

blank

拔剑吧，愿今日我能得偿心愿！



雷动于九天之上，风啸于群山之颠，风雷之剑，当世已是无人再能把用。
就让它从此安歇吧，让它长眠谷底，相伴於它原来的主人，直到永远．．．


*/

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/


// 行神如空 行气如虹
// 天盘之日，月，星 地盘之人，水，土
