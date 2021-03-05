#include <ansi.h>
inherit SKILL;

void setup()
{
	set("name","苍生诀");
	set("type","force");
	set("effective_level",100);
	set("usage/force",1);
	set("skill_class","knight");
	set("difficulty",200);
}

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	int num, hit_damage, amount, n, tt, skill;
	string msg, dot_owner, dir, index;
	mapping buff;

	skill = me->query_skill("herb",1);
	if( damage <= 0) {
		return 0;
	}
	if( skill < 250 || me->query_skill("longlife-force",1) < 180 ) {
		return 0;
	}
	if( skill < 300 ) {
		n = 3 + F_ABILITY->check_ability(me, "3_longlife_add", 3);
	} else {
		n = 5 + F_ABILITY->check_ability(me, "3_longlife_add", 3);
	}
	if( random(100) > n ) {
		return 0;
	}
	n = random(5);
	switch( n ) {
		case 0:
			msg = HIR BLK"$n"HIR BLK"口中吐出一团白雾，雾中似有一持斧巨人顶天而立。\n"NOR;
			message_vision(msg, ob, me);
			me->set_temp("timer/pfm/longlife_pangu",time());
			break;
		case 1:
			dot_owner = file_name(me);
			sscanf(dot_owner,"%s#%s",dir,index);
			dot_owner = me->query("id")+ index;
			if( !(ob->query_temp("dot/dream-herb/antbite/"+dot_owner)) ) {
				msg = HIR"$n借势喷出一口鲜血，鲜血化为血雾，迷茫在$N周围。\n"NOR;
				message_vision(msg, ob, me);
				msg = RED"$N心中一痒，有如万蚁齐蚀。\n"NOR;
				num = me->query_skill("herb")/2 + random(me->query_skill("herb")/4);
				num = num*(100+F_ABILITY->check_ability(me,"poison_dmg",2)*2)/100;
				num = COMBAT_D->magic_modifier(me, ob, "kee", num);
				ob->receive_damage("kee",num, me);
				ob->receive_wound("kee",num/2,me);
				tt = 8*(100+F_ABILITY->check_ability(me,"poison_dur",2)*5)/100;
				ob->set_temp("dot/dream-herb/antbite/"+dot_owner, 1);
				call_out("dot", 6, me, ob, tt, 0, num, dot_owner, msg);
			}
			break;
		case 2:
			if( me->query("force")+damage*2 < 2*me->query("max_force") ) {
				me->add("force",damage*2);
			} else {
				me->set("force", 2*me->query("max_force"));
			}
			me->force_status_msg("force");
			msg = WHT"你生生吐出一口鲜血，脸色却红润了起来。\n"NOR;
			tell_object(me, msg);
			break;
		case 3:
			me->delete("timer/pfm/jiuqipoxiao");
			msg = YEL"你借力冲穴，身手再无踯躅。\n"NOR;
			tell_object(me, msg);
			break;
		case 4:
			if( !ANNIE_D->check_buff(me,"knight-resistup") ) {
				buff =
				([
					"caster": me,
					"who": me,
					"type": "knight-resistup",
					"att": "bless",
					"name": "云梦五花锦·腐尸功",
					"buff1": "resistance/kee",
					"buff1_c": 30,
					"time": 20,
					"buff_msg": YEL"$N的肤色变得阴沉灰暗，带着奇异的光芒，一击之下竟隐有金石之声。\n"NOR,
				]);
				ANNIE_D->buffup(buff);
			}
			break;
	}
	return 0;
}

void dot (object me, object enemy, int total, int count, int amount, string dot_owner, string msg)
{
	int num;
	if( !me || !enemy || !enemy->is_fighting(me) ) {
		if( enemy ) {
			message_vision(RED"$N的脸色慢慢恢复了正常。。\n"NOR, enemy);
			enemy->delete_temp("dot/dream-herb/antbite/"+dot_owner);
		}
		return;
	}
	message_vision(msg,enemy);
	enemy->receive_damage("kee", amount, me);
	enemy->receive_wound("kee", amount/2, me);
	count = count+1;
	if( count < total) {
		call_out("dot", 6, me, enemy,total, count, amount, dot_owner, msg);
	} else {
		message_vision(RED"$N的脸色慢慢恢复了正常。。\n"NOR, enemy);
		if( enemy ) {
			enemy->delete_temp("dot/dream-herb/antbite/"+dot_owner);
		}
	}
	return;
}

int help(object me)
{
	write(@HELP
L100『怜苍生』（cangsheng）
将自身一部分气血立即转给队友疗伤，每20秒钟使用一次。
转移数值为苍生诀等级的五倍，转移效率为200%
耗费200点内力。

当苍生诀修炼到180级以上时，受到外界伤害时有一定几率贯通经
脉，令人做出一些平时无法实现的奇特武技，可能出现的有
1）以类似于残云碧的毒雾反击伤害者
2）将受到的伤害转为自身内力的增长
3）在短期内提高自身抵抗气血伤害的能力（+30%，十轮）
4）气贯经脉，下一个九气破霄可立即使用
5）在30秒内天人合一，可使出一招“盘古开天”
其他要求：250级药道，180级轩辕斧法
L250 药道 3%几率
L300 药道 5%几率
通过门派ability3可以增加贯通经脉的几率。
HELP
	);
	return 1;
}