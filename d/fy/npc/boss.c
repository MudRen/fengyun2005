// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// 不使用任何dodge/parry/iron-cloth
// 20M exp,long gks.
// solo? impossible! 必须有一个带double healer,带buffup等等的team。

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
	object armor,weapon;
	set_name("姜断弦", ({ "jiang duanxian","jiang"}) );
	set("title",HIW"风云第一名捕"NOR);
	set("nickname",CYN"五陵三山"NOR);
	set("gender", "男性" );
	set("age", 20+random(10));
	set("long","姜断弦睨了你一眼，说道：看什么看？没见过大魔王长什么样吗？\n\n");

	set("attitude","friendly");

	set("class","demon");
    	set("combat_exp", 20000000);	
    	set("score", 10000);
	set("per",200);
	
	set("force_factor",130+random(100));
	set("atman",1500);
	set("max_atman",1500);
	set("mana",1500);
	set("max_mana",1500);

	set("no_fly",1);
	set("no_arrest",1);

	set("boss",1);

	set("chat_chance", 1);
	set("chat_msg", ({
			"姜断弦笑道：蚩尤？蚩尤是几流货色？\n",
			"姜断弦负手望天，悠然长叹：姜某生平有十二恨。\n一恨才人無行，二恨紅顏薄命。三恨江浪不息，四恨世態炎涼。五恨月台易漏，六恨蘭葉多焦。\n七恨河豚甚毒，八恨架花生刺。九恨夏夜有蚊，十恨薜蘿藏虺。十一恨未賞敗果，十二恨天下無敵。\n",
			"姜断弦摇摇头道：什么翼人燕南天，我看也不过尔尔。\n",
			"姜断弦叹了口气道：上次燕云三十六骑尽出，倒也费了姜某一番手脚，可惜可惜。\n",
			"姜断弦睨了你一眼，说道：大魔王？大魔王就要像我这样打起来才过瘾。\n",
			"姜断弦抚着下颌道：像蚩尤那样又闪又挡的家伙，顶多算块花岗岩，算什么大魔王。\n",
			}) );

	set("resistance/gin",40);
	set("resistance/kee",40);
	set("resistance/sen",40);

	set("max_kee",256000);
	set("max_gin",192000);
	set("max_sen",128000);
	
	set_skill("heavendance",220);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",200);
	set_skill("stormdance",360);

    set_skill("perception",200);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 300);
	set_skill("force", 200);

	set_skill("hanshan-strike", 200);
	set_skill("divineforce", 200);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);

	
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "hanshan-strike");
	map_skill("force", "divineforce");
    	map_skill("blade","heavendance");
    	
	set_temp("counter_action_extra",1);
	set_temp("counter_msg",CYN"$N真气流转，身形不见凝滞，反激而回！\n"NOR);


        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

	setup();


    set("reward_npc", 1);
	set("difficulty",40);

	set_temp("apply/dodge",-999);

}

int kill_ob(object who)	
{
	object me;
	int exp_r,busyst;
	::kill_ob(who);
	stop_busy();
	smart_fight();
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

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	if (random(8))	// 每tick出8个busy? *addoil
		message_vision(CYN"\n姜断弦袍袖鼓涨，真气流动，变化无方。\n"NOR, this_object());
	else
		start_busy(1);
	return;
}


void smart_fight()
{
	object me,target,item;
	object * tar;
	object shadow,hisweapon,newweapon;
	int i,j,temp,num,temp1,num1;

	me = this_object();

	if (random(5))
		ccommand("perform force.baocanshouque");

	if (ccommand("perform force.check_gspm") && !random(5))
		ccommand("perform force.guishenpomie");
	
	tar = me->query_enemy();
	if (sizeof(tar) > 1 && random(2) && time()>query("annie/bf")+4)	// 4秒一发
	{
		set("annie/bf",time());
		message_vision(WHT"\n$N左掌划弧，右掌回圈，猛然一声大喝，发出扭曲圆转的劲力，震得所有人东倒西歪。\n"NOR,me);
		for (i=0;i<sizeof(tar) ; i++)
		{
			if (i != sizeof(tar)-1)
				target = tar[i+1];
			else
				target = tar[0];

			if (tar[i]->is_unconcious())	continue;

			target->add_temp("no_check_pfm_win",1);
			j = tar[i]->query_busy();
			tar[i]->stop_busy();
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK," ");
			target->add_temp("no_check_pfm_win",-1);
		}
		start_busy(1);
	}

	if (is_busy())
		return;

	if (!random(3) && time()>query("annie/mb")+10)	// 10秒一发
	{
		set("annie/mb",time());
		message_vision(WHT"\n$N双指一骈，指尖厉射出几道劲风，袭向众人！\n"NOR,me);
		for (i=0;i<sizeof(tar) ; i++)
		{
			target = tar[i];
			target->set("force",target->query("force")/2);
			tell_object(target,CYN"你只觉得气海一麻，已为姜断弦指力所伤！"NOR);
		}
		start_busy(1);
	}


	if (is_busy())
		return;

	target = select_opponent();

	if (!random(3) && time()>query("annie/cr")+6)	// 6秒一发。
	{
		set("annie/cr",time());
		message_vision(HIY"\n$N长袖旋身，使出「阳关三叠」之式，拍出一道劲风袭向$n！\n"NOR,me,target);
		if (random(9))
		{
			message_vision(HIY"$n只觉一道刚猛无铸的劲力如海潮般击打在自己胸上！\n"NOR,me,target);
			target->receive_damage("kee",target->query("max_kee") / 5-100,me);
			target->receive_wound("kee",target->query("max_kee") / 10-100,me);
			if (random(6))
			{
				COMBAT_D->report_status(target);
				message_vision(HIY"\n$n被打得转了一个圈子，正欲拿桩站稳，忽然胸口又一阵巨痛，如受重锤！\n"NOR,me,target);
				target->receive_damage("kee",target->query("max_kee") / 5-100,me);
				target->receive_wound("kee",target->query("max_kee") / 10-100,me);
				if (random(3))
				{
					COMBAT_D->report_status(target);
					message_vision(HIY"\n$n连转五六个圈，身形渐止，突又浑身一震，跌倒在地。\n原来姜断弦这式「阳关三叠」含有三层劲道，这才完全展开。\n"NOR,me,target);
					target->receive_damage("kee",target->query("max_kee") / 5-100,me);
					target->receive_wound("kee",target->query("max_kee") / 10-100,me);
					target->perform_busy(1);
					COMBAT_D->report_status(target);
				}
				else
				{
					message_vision(HIR BLK"$n哇的喷出一口鲜血，后退三步，勉强拿桩站稳。\n"NOR,me,target);
					target->perform_busy(1);
					COMBAT_D->report_status(target);
				}
			}
			else
			{
				message_vision(HIR BLK"$n哇的喷出一口鲜血，后退三步，勉强拿桩站稳。\n"NOR,me,target);
				target->perform_busy(1);
				COMBAT_D->report_status(target);
			}
		}
		else
		{
			message_vision(HIR BLK"$n见状大惊，身法连闪，终于险险躲过！\n\n"NOR,me,target);
			target->perform_busy(1);
		}
		start_busy(1);	// 1/8机会busy..
	}

	if (is_busy())
		return;

	if (!target->query_temp("annie/boss_needle") && target->query("kee") > 0 && !random(3))
	{
		target->set_temp("annie/boss_needle",1);
		message_vision(HIB"\n$N双指一划，一道细如发丝，迅如游电的幽幽蓝光射向$n！\n"NOR,me,target);
		target->receive_damage("kee",target->query("combat_exp") / 6000, me);
		call_out("do_chilling",5,me,target,5+random(5));
		start_busy(1);	// 1/8机会busy..
	}
	return;
}

void do_chilling(object me,object target,int count)
{
	if (!target)	// 离开战斗后同样发作。频率比正常condition快，不可解除。
		return ;
	if (!me || me->is_ghost())
	{
		target->set_temp("annie/boss_needle",0);
		tell_object(target,HIW"你中的「"HIC"青魂游魄"HIW"」终于发作空了。\n"NOR);
		return;
	}
	if (count > 0)
	{
		count = count - 1;
		tell_object(target,HIW"你中的「"HIC"青魂游魄"HIW"」发作了！\n"NOR);
		target->receive_damage("kee",target->query("combat_exp") / 6000, me);
		call_out("do_chilling",5,me,target,count);
	}
	else
	{
		target->set_temp("annie/boss_needle",0);
		tell_object(target,HIW"你中的「"HIC"青魂游魄"HIW"」终于发作空了。\n"NOR);
	}
	return;
}

void die()
{
	ccommand("fake");
	::die();
}