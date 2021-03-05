// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// 八部众之乾达婆王 梦里花落 水如昔 
// EXP 8M KEE 24K GIN/SEN 16K RESIST/ALL 60
// STR 80 DMG 77 ATTACK 76K DODGE 76K PARRY 76K
// IMMUNE TO BUSY,ABSORB IRON-CLOTH,POISON ENCHANTED
// 对抗TK有特效

// A/D/P：略高于标准8M。此人可TK。

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
		"她正立在雾生云起的隐仙岩上，一身水蓝色的绡纱长裙在烈风\n里落落翻飞，束着淡紫发带的垂腰青丝亦在风里飘舞不定，尽\n管背对着你，面貌难见，依旧让你第一眼间误以为是错坠凡间\n的仙子，此刻正欲乘风归去。\n"
		);
	set("class","demon");
    set("combat_exp", 8000000);	
    set("score", 10000);
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
	set("real_shui",1);
		
	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",24000);
	set("max_gin",16000);
	set("max_sen",16000);
	
	set_skill("heavendance",220);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("stormdance",220);
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

	set("chat_chance", 1);
        set("chat_msg", ({
                "水如昔轻轻一哼，说道："YEL"武当"NOR"？连"YEL"借力打力"NOR"都已失传，还算什么武当？\n",
                "水如昔摇摇头道："YEL"石雁"NOR"以下，个个草包，教主也太看重武当派了。\n",
                "水如昔叹道：又是一年了，不知道绽青妹妹在那边过得如何．．．\n",
                "水如昔低首看了眼袖中，自语道：这还是上次就给绽青妹妹买的，什么时候才有空送去呢？\n",
                }) );

    set("inquiry", ([
        "太极心法": "可笑"YEL"武当老掌门"CYN"去后，"YEL"太极心法"CYN"中借力打力的心诀竟\n就失传，还去我半年时间方才自镇教秘籍中找到。",
        "武当派":   "可笑"YEL"武当老掌门"CYN"去后，"YEL"太极心法"CYN"中借力打力的心诀竟\n就失传，还去我半年时间方才自镇教秘籍中找到。",
        "武当":   "可笑"YEL"武当老掌门"CYN"去后，"YEL"太极心法"CYN"中借力打力的心诀竟\n就失传，还去我半年时间方才自镇教秘籍中找到。",
        "教主":   "action水如昔拂拂耳边发丝，似乎没有听到你的声音。",
        "魔教":   "action水如昔拂拂耳边发丝，似乎没有听到你的声音。",
        "大光明教":   "action水如昔拂拂耳边发丝，似乎没有听到你的声音。",
        "西方神教":   "action水如昔拂拂耳边发丝，似乎没有听到你的声音。",
        "草包":   "action水如昔噗嗤一笑，回首顾道：譬如你，就是个大草包。",
        "大草包":   "action水如昔噗嗤一笑，回首顾道：譬如你，就是个大草包。",
        "石雁":   "说什么五行真人，还不是和他那些弟子一样大草包，死不足惜。",
        "武当老掌门":   "老掌门倒也机灵，若不是那"WHT"草包"YEL"石雁"CYN"鬼迷心窍，\n想取下这武当派还要有些曲折麻烦。\n水如昔撇撇嘴道：不过收下石雁这样的弟子，也就不过尔尔，\n识人不清，引狼入室，自绝生机，死的也不冤了。",
        "老掌门":   "老掌门倒也机灵，若不是那"WHT"草包"YEL"石雁"CYN"鬼迷心窍，\n想取下这武当派还要有些曲折麻烦。\n水如昔撇撇嘴道：不过收下石雁这样的弟子，也就不过尔尔，\n识人不清，引狼入室，自绝生机，死的也不冤了。",
        "老刀把子":   "他？只不过是局里一颗棋子，过河小卒，不值一提。",
        "木道人":   "他？只不过是局里一颗棋子，过河小卒，不值一提。",
         ]) );

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

	carry_object(__DIR__"obj/longskirt")->wear();
	carry_object(__DIR__"obj/cyin")->wield();

	carry_object(__DIR__"obj/paper5");

    set("reward_npc", 1);
	set("difficulty",20);

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

// 为了让parry busy生效(爆,太恶毒了),这里不使用mimic function....
			target->add_temp("no_check_pfm_win",1);
			j = tar[i]->query_busy();
			tar[i]->stop_busy();
			tar[i]->add("force_factor",query("force_factor")/2);
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK,WHT"银白色的丝线拂过$N，$N脚下一个不稳，身不由己的向$n攻去！"NOR);
			tar[i]->add("force_factor",-query("force_factor")/2);
			tar[i]->perform_busy(j+random(2));	// busy 0~1.
			target->add_temp("no_check_pfm_win",-1);
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


void die()
{
	object me,owner,enemy,paper,*sy_inv,things;
	int j;
	me = this_object();
	if (!query_temp("last_damage_from"))
	{
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		::die();
		return;
	}
	if (environment(me)->query("short") != "隐仙岩")
	{
		sy_inv = all_inventory(this_object());
		for(j=0;j<sizeof(sy_inv);j++){
			things = sy_inv[j];
			destruct(things);
		}
		::die();
		return;
	}
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
			enemy = owner;
	if (paper = present("paper"))
		paper->move(environment());
	enemy->set("annie/demon_killed_shui",1);	
	// not killed_shui,还有一次见面 // 此设计已取消
	message_vision(CYN"\n$N微一皱眉，哼道：却还有三分本事，可惜我青虹针浪费给了那个草包。
$N道：今日且住，如若有缘，日后自当再与你相见！\n$N右手虚虚一按，整个人飘飞而起，消失在隐仙岩外的云海中。\n$n追上岩石一看，只见苍茫云海，迷蒙雾气，却哪里还有$N的踪影？\n\n一张小纸片飘飘悠悠的落到地上。\n\n"NOR,me,enemy);
//	REWARD_D->riddle_done(enemy,"背叛",100,1);
	destruct(me);
	return;
}

