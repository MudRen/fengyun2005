//========================云龙九现====================================
// --------   neon
// Modified by Silencer: Is this a super-gin-killer? Nope, DWG has spirit and bloodcurse

#include <ansi.h>
#include <combat.h>
inherit SSERVER;


int perform(object me, object target)
{
	string msg;
	int celeskill, celepower, i, skill, total, enhance;
	int hit, busy, damage, ability, ap, super;
	
	object weapon;
	string name, name1;
	string *perform_msg = ({
	HIW "白练腾空"NOR WHT" － $N"WHT"手中$W"WHT"如白虹腾起天空，罩向$n。\n"NOR,
	HIW "浮游逍遥"NOR WHT" － $N"WHT"身法飘摇，$W"WHT"在奇幻的身影中抖出几个回环击向$n。\n"NOR,
	HIW "携雷掣电"NOR WHT" － $N"WHT"手中$W"WHT"化作一道闪电射向$n。\n"NOR,
	HIW "腾蛇乘雾"NOR WHT" － 在劈裂空气的爆响声中$W"NOR+WHT"如雾里现身的飞龙，击向$n。\n"NOR,
	HIW "龙见而雩"NOR WHT" － $W"WHT"如蛰龙初起，向$n"NOR+WHT"游动，霎时间化作一蓬鞭雨，洒向$n。\n"NOR,
	HIW "龙图出河"NOR WHT" － $N"WHT"手中$W"WHT"折转空灵，在空中幻出一个个赤文篆字印向$n。\n"NOR,
	HIC "天行健，当自强不息"NOR WHT" － $N"WHT"宁心提气，顿时天人合一，$W"NOR+WHT"平平常常一挥而出，却无可抵挡。\n"NOR,
	YEL "地势坤，以厚德载物"NOR WHT" － $N"WHT"一盘手中$W"WHT"，一道道厚实柔韧的内劲如游龙般围上$n。\n"NOR,
	HIG "天道自然"NOR WHT" － $N"WHT"凝鞭不发，忽然空中幻出众多生灵，种种天象展示在苍茫天地间。\n"WHT
	"$n不由得震慑于自然力的多彩与伟大。\n"NOR});

	if( me->query("class") != "yinshi" ) {
		return notify_fail("只有帝王谷弟子可以使用"WHT"『云龙九现』"NOR"。\n");
	}
	weapon = me->query_temp("weapon");
	skill = me->query_skill("thunderwhip",1);
	celeskill = me->query_skill("celecurse", 1);
	if( skill < 110 || celeskill < 110 ) {
		return notify_fail("『云龙九现』需要110级的通天降和天雷鞭法！\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail(WHT"『云龙九现』"NOR"只能对战斗中的对手使用。\n");
	}
	ap = me->query_skill("cursism"); 
	if( userp(me) && ap >= 500 ) {
		ap = 500; // got to cap it.
	}
	if( celeskill >= 200 && (me->query_skill("qiankunwuxing",1) >= 200 || !userp(me)) ) {
		// 2040 for 4 busy.
		hit = 9;
		busy = 4;
		name ="云龙九现"; 
		name1 = "终极杀式"; 
		damage = (140+ap*ap*ap/80000)*120/100;
	} else if( celeskill >= 160 ) {
		// 160-200, enable 400-500. dmg 1226 - 1862. for 4 busy
		hit = 6;
		busy = 4;
		name ="云龙六现";
		name1 = "中级杀式"; 
		damage = 300 + ap*ap*ap/80000;
	} else {
		// 110-160,1.1-3.1M, enable 250-400,dmg 560-860 for 3 busy
		hit = 3;
		busy = 3;
		name ="云龙三现";
		name1 = "初级杀式"; 
		damage = 60+ap*2;
	}
	enhance = 200;
	ability = F_ABILITY->check_ability(me,"yljx_add")*2;
	damage = damage * (100 + ability)/100;
	damage = COMBAT_D->magic_modifier(me, target, "gin", damage)/hit;
	message_vision(WHT"\n\n$N的鞭法一变，招式展开如层层密布的浓云，雨将落未落，风欲起未起
"HIC"使出了天雷破的"+ HIC+ name1 + HIC"  －  『"HIC+ name +"』！！\n\n"NOR, me);

	for( i = 0; i < hit; i++ ) {
		msg = perform_msg[i];
		msg = replace_string(msg,"$W", weapon->name()+WHT);
		message_vision("\n" + msg, me, target);
		if( COMBAT_D->do_magic_attack(me, target, "cursism", "gin", enhance ) || target->is_unconcious() ) {
			message_vision(MAG+weapon->name()+MAG"发出一丝丝幽幽的紫光，渗入$n"NOR+MAG"体内...\n"NOR, me, target);
			target->receive_damage("gin", damage,me);
			target->receive_wound("gin",damage/4, me);
		} else {
			message_vision(CYN"$N吐气旋身，闪过了$n"CYN"的鞭影。\n"NOR,target,me);
		}
	}
	if( hit == 9 ) {
		message_vision(HIG"\n\n$N"+HIG"凝鞭收势，心神与天地融为一体，周身无懈可击。\n\n"NOR, me);
	}
	message_vision("\n",target);
	COMBAT_D->report_status(target);
	COMBAT_D->win_lose_check(me, target, 1);
	super = me->query_skill("flying-dragon",1);
	if( super >= 100 ) {
		//super = (super-100)/20+F_ABILITY->check_ability(me,"3_yl9x_add",3)/2;
		super = (super-100)/10+F_ABILITY->check_ability(me,"3_yl9x_add",3);
		if( random(100) < super && me->query_temp("yl9x_times") < 2 ) {
			me->add_temp("yl9x_times",1);
			message_vision(WHT"$N一口真气吐出，身法竟然丝毫不显迟滞。\n"NOR, me);
			busy = 0;
		} else {
			me->set_temp("yl9x_times",0);
		}
	}
	me->perform_busy(busy);
	return 1;
}