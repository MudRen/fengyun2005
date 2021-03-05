// lotusforce.c
#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","莲华心法");
	set("type","force");
	set("usage/force",1);
	set("skill_class","bonze");
	set("effective_level",120);
	set("difficulty",400);
}


int valid_learn(object me){
	if((int)me->query_skill("buddhism",1) < (int)me->query_skill("lotusforce",1)){
		return notify_fail("你的大乘佛法修为不够，无法领会更高深的莲华心法。\n");
	}
	return 1;
}

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	int /*num,*/ hit_damage, amount;
	
	if (damage <=0)	return 0;	
	if( me->query_temp("pfm/xg_preservation")<=0)
		return 0;
	
	me->add_temp("pfm/xg_preservation",-1);
	
	data["msg"] = CYN"$n"NOR+CYN"的身畔清风荡溢，$N"NOR+CYN"一阵踯躅。\n"NOR;
	
	hit_damage = me->query_skill("buddhism",1)*10;	
	if (ob->query_hate(me)>0)
		ob->add_hate(me,-hit_damage);
	if ((amount = ob->query_hate(me))<0)
		ob->add_hate(me, -amount);	// 0
				
	if (me->query_temp("pfm/xg_preservation") < 1) {
			ANNIE_D->debuff(me, "xg-detaunt");
	}	
	return data;	
}


int help(object me)
{
	write(@HELP   
莲华心法的学习需要同等级的大乘佛法为基础

『斗战胜诀』〔douzhansheng〕
至少需要20级八识神通和20级莲华心法
在短时期内用八识神通压抑自身精气神的损伤
其气血效果为	L20八识神通（500）、L70（1000）、L110（1500）、
		L150（2000）、L190（2500）
精力和心神效果为500
但是该伤势在三分钟后会复发，精气神值降低相同的数值
（但不会因低于零而造成死亡） 
	
『诛仙诀』（zhuxian）
需140级莲华心法。神识、光识伤害力增加５０％，闪躲招架力提高，
但是不能使用除斗战胜外的疗伤武功。
		
『慈悲诀』 （其中大于150等级为八识神通等级）
heal:20级莲华心法20级八识神通，-100内力，+300气血，速度2秒
mheal:80级莲华心法80级八识神通，-200内力，+600气血，速度2秒
gheal:120级莲华心法120级八识神通，-300内力，+1500气血，速度4秒
sheal:150级莲华心法180级八识神通，-500内力，+4000气血，速度6秒
fheal:150级莲华心法190级八识神通，-500内力，+3000气血，速度4秒
cheal:150级莲华心法200级八识神通，-600内力，+8000气血，速度10秒
自我忙乱均为1轮

『佛门狮子吼』(roar)
需150级莲华心法，震撼在场所有敌人，并停止自己和队友对敌人的战
斗，在此期间（10轮）敌人若受到伤害自动解除震撼状态。
消耗300点内力。

『晦明隐』(fade)
需150级莲华心法，210级八识神通，使用此心法时若被敌人击中
可降低敌人对自己的憎恨使其转向他人。每20分钟使用一次。
每次延续30秒或被敌人击中3次后失效。

『日月光佛』（avatar）
需150级莲华心法，220级八识神通，
使用此心法可提高自己或队友的战斗属性（力量/定力/速度：+20）
每20分钟使用一次，每次持续3分钟。

『战佛诵』（zhanfo）
需150级莲华心法，150级八识神通，
发动后『龙现于野』额外伤害力＊３
但同时『慈悲诀』不可使用。技能CDT30秒。

『战佛诵消散』（zhanfooff）
需150级莲华心法，
消散已经运行的『战佛诵』。
消散后后遗症期间仍然无法使用『慈悲诀』。
后遗症持续3分钟。技能CDT30秒。

HELP
    );
    return 1;
}