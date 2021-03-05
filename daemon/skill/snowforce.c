 // annie 6.27
// dancing_faery@hotmail.com

#include <combat.h>
#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","冷雪心经");
	set("type","force");
	set("usage/force",1);
	set("skill_class","moon");
	set("effective_level",130);
	set("difficulty",200);
	set("no_refund",({"chillblade"}));
}

mapping ob_hit(object ob, object me, int damage)
{
	string msg;
	mapping buff;
	int i, n;
	int *hits;

	if( ANNIE_D->check_buff(me,"shinra") < 1 && ANNIE_D->check_buff(me,"shine") < 1 ) {
		return 0;
	}
	if( ANNIE_D->check_buff(me,"shinra") > 0 ) {
		if( !ANNIE_D->check_buff(ob,"lowresist2") ) {
			buff =
				([
					"caster":me,
					"who":ob,
					"type":"lowresist2",
					"att":"curse",
					"name":"天岚凝舞·雾影神罗",
					"buff1":"resistance/sen",
					"buff1_c":-50,
					"time":6,
					"buff_msg":CYN"寒霜飞舞，$N"CYN"渐觉心神慌乱。\n"NOR,
				]);
			ANNIE_D->buffup(buff);
		}
	}
	if( ANNIE_D->check_buff(me,"shine") > 0 ) {
		if( me->query_temp("weapon") && me->query_temp("weapon")->query("ice_blade") && ANNIE_D->check_buff(me,"enchantweapon") > 0 ) {
			if( me->query_skill("chillblade",1) >= 190 && me->query_skill("stormdance",1) >= 130 ) {
				n = 2;
			} else {
				n = 1;
			}
			hits = me->query_temp("marks/shine_hits");
			if( !hits ) {
				hits = ({});
			}
			hits += ({ time() });
			for( i = 0; i < sizeof(hits); i++ ) {
				if( hits[i] + 30 < time() ) {
					hits -= ({ hits[i] });
				}
			}
			hits -= ({ 0 });
			me->set_temp("marks/shine_hits", hits);
			if( n == 1 ) {
				message_vision(CYN"\n一缕淡青色的光芒流动到$N"CYN"手中的"+me->query_temp("weapon")->name()+CYN"里……\n"NOR,me);
			} else {
				message_vision(CYN"\n青芒回旋，$N"CYN"手中的"+me->query_temp("weapon")->name()+CYN"似有灵性般长鸣。\n"NOR,me);
			}
			if( wizardp(me) && (string)me->query("env/combat1") == "verbose" ) {
				tell_object(me,"流光 has accumulated " + sizeof(hits)*5*n + "% damage.\n");
			}
			return 0;
	/*		for (i=0; i<14; i++)
			{
				if (ANNIE_D->check_buff(me,"shine"+i))	continue;
				msg="愿我如星君如月夜夜流光相皎洁";

				buff =
						([
								"caster":me,
								"who":me,
								"type":"shine"+i,
								"att":"bless",
								"name":msg[i*2..i*2+1],
								"buff1":"annie/chillblade_extradamage",
								"buff1_c":damage/15,
								"time":30,
								"warn_msg":" ",
								"buff_msg":CYN"一缕淡青色的光芒流动到$N"CYN"手中的"+me->query_temp("weapon")->name()+CYN"里……\n"NOR,
						]);
				ANNIE_D->buffup(buff);*/			
		}
	}
	return 0;
}

int skill_difficulty()
{
	object me = this_player();
	int skill;
	if( me && userp(me) ) {
		skill = me ->query_skill("snowforce", 1);
		if( skill < 170 ) {
			return 200;
		} else {
			return 300;
		}
	}
	return 200;
}

int help(object me)
{
	write(@HELP   
冷雪心经级别170以上，学习系数增加到300。

L60 『霜华凝结』（shuanghuaningjie）
令所有在场对手忙乱两轮，15分钟使用一次
卷一：再次使用时间12分钟
卷二：再次使用时间降低到10分钟
卷三：再次使用时间降低到5分钟

L90 『静影长空』（jingyingchangkong）
增加自己或队友的最大内力，持续时间15分钟。
L90：+500最大内力
L170：+1000最大内力
作用于他人效果减半

L120『冰魄晶壁』(bingpojingbi)
该特技必须阅读冰魄晶壁－第一卷后才能使用
凝聚成一面冰晶之壁在战斗中阻挡对手的攻击
60秒使用一次，自我忙乱2回合，冰壁在60秒后消失
第一卷：阻挡几率１０％
第二卷：阻挡几率２０％
第三卷：阻挡几率３０％

L160『阴陵扣命』（yinlingkouming）
一般来说，拿着武器的敌人会伤害你的气血上限，此招
可使敌人手足无力，无法伤害气血上值（魔法类武功除
外），若成功持续20秒，自我忙乱一回合。
此特技对ＢＯＳＳ无效。

HELP
    );
    return 1;
}
