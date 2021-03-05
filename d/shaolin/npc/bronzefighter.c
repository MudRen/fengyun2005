// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
	set_name("铜人", ({ "bronze fighter"}) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 3);
	set("max_kee", 99900);
	set("max_gin", 99900);
	set("max_sen", 99900);
	set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "hoof"}) );
	set("combat_exp", 3500000);
	set_temp("apply/attack", 400);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge",40);
	setup();
}

void do_perform(object target,int count)
{
	object me = this_object();
	object weapon;
	int extra=200,hisexp,myexp,lvl,yourexp,mod=10,i;
	string msg;
		string *style = ({
HIR "左铜人手中"CYN"独脚胖嘟嘟"HIR"突发红光，急劈$n的左肩！" NOR,
HIY "右铜人手中"CYN"独爪胖嘟嘟"HIY"突发黄光，直取$n的右腹！" NOR,
HIW "前铜人手中"CYN"独脚胖嘟嘟"HIW"突发白光，径砍$n的左腿！" NOR,
HIG "后铜人手中"CYN"独爪胖嘟嘟"HIG"突发绿光，平削$n的天门！" NOR,
HIB "左前二铜人手中"CYN"独脚胖嘟嘟"HIB"和右后二铜人手中的"CYN"独爪胖嘟嘟"HIB"交织错合，泛出层层黑气，网向$n小腹！" NOR,
});

	string *style2 = ({
"龙形－－$N抡动手中"CYN"独脚胖嘟嘟"HIY"，棍风呼啸，打向$n的小腹！",
"凤形－－$N手中"CYN"独爪胖嘟嘟"HIY"化做棍影重重，将$n团团围住！",
"虎形－－$N向前一纵，手中"CYN"独脚胖嘟嘟"HIY"狂舞，向$n猛扑过去！",
"豹形－－$N欺身急进，手中"CYN"独爪胖嘟嘟"HIY"头尾齐出，分打$n的两处要害！",
"鹤形－－$N手中"CYN"独脚胖嘟嘟"HIY"一顿，暗蓄内力，点向$n的小腹！",
"猿形－－$N身形连纵连跃，手中"CYN"独爪胖嘟嘟"HIY"威势陡增，连连向$n打去！",
"蛇形－－$N身影绕着$n连续晃动，手中"CYN"独脚胖嘟嘟"HIY"连发，扫向$n的小腹！",
"鹰形－－$N身形纵起，手中"CYN"独爪胖嘟嘟"HIY"自上而下，迅猛无比，砸向$n的小腹！"});
	if (!target || !count)
		return;
	switch (count)
	{
	case 1:
			weapon = target->query_temp("weapon");
			myexp = (int)me->query("combat_exp");
			hisexp= (int)target->query("combat_exp");
			if(random(hisexp) < myexp && weapon)	
			{
			message_vision(
		HIW "\n\n$N使出一式锁梦缠魂枪，枪身似灵蛇般缠住$n手中的兵刃，"+ 
		weapon->name()+  "脱手而飞！\n\n" NOR, me,target);
			if( weapon->unequip()) weapon->move(environment(target));
			}
			else
			{
				me->add_temp("apply/attack", extra);
				me->add_temp("apply/damage", extra*2);
			msg = HIR+ "\n\n$N使出一式锁梦缠魂枪，手中的"CYN"独脚胖嘟嘟"HIR"如灵蛇般直咬$n的$l！\n\n"+ NOR;
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
				me->add_temp("apply/attack", -extra);
				me->add_temp("apply/damage", -extra*2);
			}
		break;
	case 2:

    	myexp = (int) me->query("combat_exp");
    	hisexp= (int)target->query("combat_exp");
    	weapon = me->query_temp("weapon");
    
    	message_vision(HIW"\n苦海茫茫，何处是岸？$N手中的"CYN"独爪胖嘟嘟"HIW"忽然幻出个十数个『茫』字！\n"NOR,me);

    	myexp=myexp/2+random(myexp)*5/2;
    
    	if(hisexp < myexp)
    	{
			target->force_busy(8);
			message_vision(YEL"$N被杖法所惑，动作慢了下来！\n\n"NOR,target);
    	}
    	else
			message_vision(HIR"$N忽然整个人飞起贴在杖上，$n的杖花顿时消失无踪！\n\n"NOR,target,me);		

		break;
	case 3:
			myexp = (int) me->query("combat_exp");
			yourexp = (int) target->query("combat_exp")* mod/10;

			lvl = 8;
				
			msg = HIR "\n$N"HIR"使出大悲千叶掌法中的『千手千变』，幻出无数掌影击向$n！" NOR;
			if( random(myexp * lvl+yourexp) <myexp*lvl )
			{
				message_vision(msg + "\n", me, target);
				msg = "结果$n被$N攻了个手忙脚乱！\n";
				message_vision(msg, me, target);
				target->force_busy(8);
				target->set_temp("busy_timer/dabei-strike",time());
			}
			else
			{
				me->add_temp("apply/attack",extra/2);
				COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
				me->add_temp("apply/attack",-extra/2);
			}		break;
	case 4:
		for (i=0; i<5;i++ )
		{
			me->add_temp("apply/attack",extra*i/2);
			me->add_temp("apply/damage",extra*i/2);
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,style[i]);
			me->add_temp("apply/attack",-extra*i/2);
			me->add_temp("apply/damage",-extra*i/2);
		}
		break;
	case 5:

		msg = HIY  "$N使出反转流星锤法中的［反背连环］，假意抽身急退，蓦地反身抖手一锤！" NOR;      	
        	me->add_temp("apply/attack",extra/2);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/attack",-extra/2);
		msg = HIY  "$N紧跟一招，另一锤反身又是一锤！！" NOR;
        	me->add_temp("apply/attack",extra/2);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/attack",-extra/2);
        	msg = HIY  "$N竟然还不回头，两臂一振，再来一锤！" NOR;
        	me->add_temp("apply/attack",extra/2);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/attack",-extra/2);
		break;
	case 6:
			weapon = target->query_temp("weapon");
			myexp = (int)me->query("combat_exp");
			hisexp= (int)target->query("combat_exp");
			
			if(random(hisexp) < myexp  && weapon && random(2))	
			{
			message_vision(
		HIW "\n\n$N使出一式［一切随缘］，剑身似灵蛇般缠住$n手中的兵刃，"+ 
		weapon->name()+  HIW"脱手而飞！\n\n" NOR, me,target);
			if( weapon->unequip()) weapon->move(environment(target));
			}
			else
			{
					me->add_temp("apply/attack", extra*2);
					me->add_temp("apply/damage", extra*2);
				msg = HIR+ "\n\n$N使出一式［一切随缘］，手中的"CYN"独脚胖嘟嘟"HIR"如闪电般直刺$n的$l！\n\n"+ NOR;
				COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
					me->add_temp("apply/attack", -extra*2);
					me->add_temp("apply/damage", -extra*2);
			}
		break;
	case 7:
	 	msg = HIR "\n\n"+
	"青$N手中的"CYN"独脚胖嘟嘟"HIR"大力从上往下抽出，\n黄$N手中的"CYN"独爪胖嘟嘟"HIR"展开，拦腰横扫，\n"+
        "紫$N手中的"CYN"独脚胖嘟嘟"HIR"鞭随身起，撩向下盘，\n"+
        "锈$N手中的"CYN"独爪胖嘟嘟"HIR"贯力直刺，\n"+
"同时使用梵音天龙鞭法，高喝道：四－－爪－－天－－龙！！\n手中的家伙同时击到！！" NOR;
		message_vision(msg,me,target);
		for (i=0; i<4;i++ )
		{
			me->add_temp("apply/attack",extra*i);
			me->add_temp("apply/damage",extra*i);
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM," ");
			me->add_temp("apply/attack",-extra*i);
			me->add_temp("apply/damage",-extra*i);
		}
		break;
	case 8:
			me->add_temp("apply/attack",extra);
				msg = HIY  "$N"HIY"使出悟彻波风斧法中的『三板斧』，一招连环几斧，手中的"CYN"独爪胖嘟嘟"HIY"劈山般向$n"HIY"砍出第一斧！" NOR;
			COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
			
			msg = HIY  "第二斧！" NOR;
				me->add_temp("apply/damage",extra);
				COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
				
					msg = HIY  "第三斧！" NOR;
				me->add_temp("apply/damage",extra);
				COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
				me->add_temp("apply/damage",-extra);    

					me->add_temp("apply/damage",-extra);
			   me->add_temp("apply/attack",-extra);
	

		break;
	case 9:
		        msg = HIR+"$N施展出刚阳的一阳指，"+ HIY +
        	"无数指影夹杂着炽热的指风，点向$n的全身！\n\n" + NOR;
					me->add_temp("apply/attack", extra*2);
					me->add_temp("apply/damage", extra*2);
				COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
					me->add_temp("apply/attack", -extra*2);
					me->add_temp("apply/damage", -extra*2);
		break;
	case 10:
		for (i=0; i<8;i++ )
		{
			me->add_temp("apply/attack",extra*i);
			me->add_temp("apply/damage",extra*i);
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,HIY+style2[i]+NOR);
			me->add_temp("apply/attack",-extra*i);
			me->add_temp("apply/damage",-extra*i);
		}
		break;
	}
	
}