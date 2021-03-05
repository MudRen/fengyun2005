// sillencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *ob;
	int i, skill, my_exp, his_exp, bonus,num, enhance, tt, crit, suc;
	string msg, dot_owner, dir, index;

	if( me->query("class") != "knight" ) {
		return notify_fail("只有快活林弟子才能够使用"+HIG"『残云碧』"NOR+"。\n");
	}
	if( me->query_skill("dream-herb",1) < 100 ) {
		return notify_fail("『残云碧』需要100级的云梦五花锦。\n");
	}
	if( !me->is_fighting() ) {
		return notify_fail("『残云碧』只能在战斗中使用。\n");
	}
	skill = me->query_skill("herb");
	bonus = me->query_skill("dream-herb",1);
	if( userp(me) ) {
		if( me->query("force") < 100 ) {
			return notify_fail("残云碧需要100点内力。\n");
		}
		me->add("force", -100);
	}

	msg =  HIG "$N真气流转，脸色突然变得碧绿阴沉。。\n\n" NOR;
	message_vision(msg, me);
	msg = HIG "$N"HIG"猛一咬舌尖，使出云梦五花锦中至阴至毒的『归鸿声断残云碧』！！ 
碧血有如残云浓雾一般，漫天纷纷洒落。\n\n" NOR;
	message_vision(msg, me);
	me->add_temp("apply/herb",bonus*2);
	ob = all_inventory(environment(me));
	dot_owner = file_name(me);
	sscanf(dot_owner,"%s#%s", dir, index);
	dot_owner = me->query("id") + index;
	suc = 2;
	for( i = 0; i < sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i] == me ) {
			continue;
		}
		if( !ob[i]->is_fighting(me) ) {
			continue;
		}
		if( ob[i]->query_temp("dot/dream-herb/cyb/"+dot_owner) ) {
			continue;
		}
		if( COMBAT_D->do_magic_attack(me, ob[i], "herb", "kee", 0) ) {
			msg = HIR "五花毒雾无声无息地渗入$n的体内．．．\n" NOR;
			message_vision(msg, me, ob[i]);
			suc = 3;
			msg = YEL"$N只觉眼前"+HIG"五"+HIG"彩"+HIM"斑"+HIY"斓"NOR+YEL"，似乎有无数只小虫在飞舞。\n"NOR;
			crit = 0;
			if( me->query_skill("herb",1) >= 210 ) {
				crit = crit + (me->query_skill("herb",1)-200)/10;
			}
			if( crit > 10 ) {
				crit = 10;
			}
			crit += F_ABILITY->check_ability(me, "3_canyunbi_add", 3);
			// 275 + random(137)
			// -- 275*8 + random(1000) = 2200 + random(1000)	in 24 turns
			// with ability it's,+20% damage, *150% duration
			// (275*1.2 + random(137)*1.2) * 12 = 3960 + random(1972) in 36 turns
			num = skill/2 + random(skill/4);
			num = num*(100+F_ABILITY->check_ability(me,"poison_dmg",2)*2)/100;
			if( crit + 5 > random(100) ) {
				num = num*2;
				msg = YEL"※$N只觉眼前"+HIG"五"+HIG"彩"+HIM"斑"+HIY"斓"NOR+YEL"，似乎有无数只小虫在飞舞。※\n"NOR;
			}
			message_vision(msg,ob[i]);
			num = COMBAT_D->magic_modifier(me, ob[i],"kee",num);
			ob[i]->receive_damage("kee", num, me);
			ob[i]->receive_wound("kee", num/2, me);
			tt = 8*(100+F_ABILITY->check_ability(me,"poison_dur",2)*5)/100;
			ob[i]->set_temp("dot/dream-herb/cyb/"+dot_owner,1);
			call_out("dot", 6, me, ob[i], tt, 0, num, dot_owner, msg);
		} else {
			tell_object(me, HIW"你的五花毒雾被"+ob[i]->name()+"发现了！！\n"NOR);
		}
	}
	me->add_temp("apply/herb",-bonus*2);
	me->perform_busy(suc);
	return 1;
}


void dot (object me, object enemy, int total, int count, int amount, string dot_owner, string msg)
{
	int num;
	if( !me || !enemy || !enemy->is_fighting(me) ) {
		if( enemy ) {
			message_vision(YEL"$N的脸色慢慢恢复了正常。。\n"NOR, enemy);
			enemy->delete_temp("dot/dream-herb/cyb/"+dot_owner);
		}
		return;
	}
	message_vision(msg, enemy);
	enemy->receive_damage("kee", amount, me);
	enemy->receive_wound("kee", amount/2, me);
	count = count+1;
	if( count < total ) {
		call_out("dot", 6, me, enemy, total, count, amount, dot_owner, msg);
	} else {
		message_vision(YEL"$N的脸色慢慢恢复了正常。。\n"NOR,enemy);
		if( enemy ) {
			enemy->delete_temp("dot/dream-herb/cyb/"+dot_owner);
		}
	}
	return;
}