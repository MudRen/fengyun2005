// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>

int cast(object me, object target)
{
	int extra;
	int amount, friend_amount;
	int i, num;
	object *myteam, *team;
	mapping buff;
	string msg;

	if( me->query("class") != "lama" ) {
		return notify_fail("只有大昭寺的弟子才能使用观音六字明咒。\n");
	}
	extra = me->query_skill("kwan-yin-spells", 1);
	if( extra < 140 ) {
		return notify_fail("『叭』需要140级的观音六字明咒。\n");
	}
	target = me;
	if( ANNIE_D->check_buff(me, "forceshield") ) {
		return notify_fail("你已经在运法之中了。\n");
	}
	if( (int)me->query("mana") < 100 ) {
		return notify_fail("需要100点的法力。\n");
	}
	if( userp(me) ) {
		me->add("mana", -100);
	}
	message_vision(HIW "\n$N"HIW"右手摆在胸前，中指微曲，拇指搭在中指侧，其余三指展开如莲花初放，念道：『叭』 \n"NOR, me, target );

	msg = "$N浑身上下渐渐泛出一圈圣洁的光华，令人难以正视。\n";

	if( extra >= 220 ) {
		amount = 3000;
		friend_amount = 200;
		msg = HIR"$N"HIR"浑身上下渐渐泛出一圈圣洁的光华，令人难以正视。\n"NOR;
	} else if( extra >= 180 ) {
		amount = 250;
		friend_amount = 150;
		msg = HIY"$N"HIY"浑身上下渐渐泛出一圈圣洁的光华，令人难以正视。\n"NOR;	
	} else {
		amount = 200;
		friend_amount = 100;
		msg = HIC"$N"HIC"浑身上下渐渐泛出一圈圣洁的光华，令人难以正视。\n"NOR;
	}
	me->perform_busy(2);
	buff = 
		([
			"caster":me,
			"who":me,
			"type":"forceshield",
			"att":"bless",
			"name":"观音六字明咒·『叭』",
			"time":90,
			"buff_msg":msg,
			"disa_msg":YEL"你身上的光华渐渐消失了。。\n"NOR,
			"shield_desc":CYN"$n身上的光华消融了$N的攻势。\n"NOR,
			"shield_amount":amount,
			"shield_type":"mana",
		]);
	ANNIE_D->buffup(buff);
		
	myteam = me->query_team();	
	if( myteam && extra >= 120 ) {
		team = filter_array(myteam, (: present($1, environment($2)) :), me);
		num = sizeof(team);
		for( i = 0; i < num; i++ ) {
			if( ANNIE_D->check_buff(team[i], "forceshield") ) {
				continue;
			}
			if( team[i] == me) {
				continue;
			}
			buff = 
				([
					"caster":me,
					"who":team[i],
					"type":"forceshield",
					"att":"bless",
					"name":"观音六字明咒·『叭』",
					"time":90,
					"buff_msg":CYN"$N浑身上下渐渐泛出一圈圣洁的光华，令人难以正视。\n"NOR,
					"disa_msg":YEL"你身上的光华渐渐消失了。。\n"NOR,
					"shield_desc":CYN"$n身上的光华消融了$N的攻势。\n"NOR,
					"shield_amount":friend_amount,
					"shield_type":"mana",
				]);
			ANNIE_D->buffup(buff);
		}
	}
	return 1;
}
