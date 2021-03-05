#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","寒梅心法");
	set("type","force");
	set("effective_level",100);
	set("difficulty",200);
	set("usage/force",1);
	set("skill_class","huashan");
	
}

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	int num, x, dmg;
	
	if ((x=me->query_temp("pfm/hs_mthy_shield")>0)) {
		message_vision(WHT"$N"NOR WHT"身畔寒星忽由微光遽变作厉芒，激射$n"NOR WHT"，竟是避无可避！\n"NOR, me, ob);
		COMBAT_D->report_status(ob);
		dmg = COMBAT_D->magic_modifier(me, ob, "kee", me->query_skill("tanzhi-shentong",1)); // 160 per hit
		ob->receive_damage("kee", dmg, me);
		if (me->query_temp("pfm/hs_mthy_shield")<2)
			me->delete_temp("pfm/hs_mthy_shield");
		else
			me->add_temp("pfm/hs_mthy_shield",-1);
	}
		
	if (damage <=0)	return 0;		
	if( me->query_temp("pfm/hs_yingyueliuhui")<=0
		|| me->query("class")!= "huashan"
		|| me->query_skill_mapped("iron-cloth")!= "spring-water")
		return 0;
	
	num = me->query_temp("pfm/hs_yingyueliuhui");
	
	if (!random(4)){
		me->add_temp("pfm/hs_yingyueliuhui",-1);
		data["msg"] = WHT"$N一招攻去，却如攻入波光幻影，失去了$n的行踪！\n"NOR,
		data["damage"] = - damage;
		if (me->query_temp("pfm/hs_yingyueliuhui") <= 0) {
			ANNIE_D->debuff(me, "hs_yylh");
		}	
	} 	
	return data;	
}


int help(object me)
{
	write(@HELP   
『寒霜诀』（chill）
攻击身畔所有对手，攻击力随寒梅心法提高，每次耗费50点内力。
额外攻击力=寒梅心法等级

『傲霜诀』（aoshuang）
疗伤心法，可在战斗中使用，可用于自身或队友，自我忙乱1回合
疗伤速度（生效时间）3秒。
Ｉ：	需20级寒梅心法，恢复250点气血，耗费100点内力
ＩＩ：	需50级寒梅心法，恢复400点气血，耗费150点内力
ＩＩＩ：需100级寒梅心法，恢复800点气血，耗费200点内力
ＩＶ：	需150级寒梅心法，恢复1200点气血，耗费250点内力
Ｖ：	需200级寒梅心法，恢复1600点气血，耗费300点内力

『化霜诀』〔remedy〕
疗伤心法，可在战斗中使用，可用于自身或队友，自我忙乱1回合
在40回合内持续治疗10次。
Ｉ：	需150级寒梅心法，每次恢复200点气血，共耗费200点内力
ＩＩ：	需170级寒梅心法，每次恢复250点气血，共耗费250点内力
ＩＩＩ：需200级寒梅心法，每次恢复300点气血，共耗费300点内力

『破霜诀』〔elixir〕
疗伤心法，可在战斗中使用，同时作用于在场所有队友，自我忙乱1回合
在32回合内持续治疗8次，可与『化霜诀』叠加。
需200级寒梅心法和200级幻风飘云舞，每次恢复250点气血
共耗费400点内力

『绛雪玄霜』（divine）
作用于在场的所有队友，平均分布所有人的气血值，无自我忙乱
需200级寒梅心法和200级幻风飘云舞。每15分钟使用一次。

HELP
    );
    return 1;
}
