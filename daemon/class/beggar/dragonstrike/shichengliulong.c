#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, myexp, enemyexp, lvl, chance;
	object weapon, hisweapon;
	int mod;
	mapping buff;
	
	lvl = (int) me->query_skill("dragonstrike",1);
	if( lvl < 90 ) {
		return notify_fail("『时乘六龙』需要90级的降龙十八掌。\n");	
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『时乘六龙』只能对战斗中的对手使用。\n");
	}
	
	if( ANNIE_D->check_buff(target,"pseudo-busy") ) {
		return notify_fail(target->name()+"已经破绽毕露，还不趁机进攻！\n");	
	}
	mod = COMBAT_D->can_busy(me, target, "dragonstrike");	
	if( !mod ) {
		return notify_fail(HIW"此人功力深湛，贸用此招恐非敌手。\n"NOR);
	}
	lvl = 300;
	msg = HIY"
$N"HIY"倏然进身拍出一掌，虽不过是一掌，却暗含六道劲力，隐隐将$n"HIY"上下
笼於其中。$n"HIY"略一迟疑，$N"HIY"后掌推前掌，双掌力道并在一起，排山倒海
的压将过来。只一瞬之间，掌力竟如怒潮狂涌，势不可当，犹如是一堵无
形的高墙，向$n"HIY"身前疾冲。\n"NOR;

	message_vision(msg, me, target);
	
	if( COMBAT_D->do_busy_attack( me, target, "dragonstrike/shichengliulong", "unarmed", lvl, mod) || target->query("race") != "人类" ) {
		message_vision(BLU"$n"NOR+BLU"只觉掌风扑面，气息窒滞。\n"NOR, me, target);
		buff =
		([
			"caster":me,
			"who":target,
			"type":"pseudo-busy",
			"att":"curse",
			"name":"降龙十八掌·时乘六龙",
			"time":8,
			"buff1":"pseudo-busy",
			"buff1_c":1,
			"buff_msg":"",
			"condition_type":"<身法迟钝>",
			"warn_msg":" ",
			"disa_type":0, 
		]);
		ANNIE_D->buffup(buff);	
		target->set_temp("busy_timer/dragonstrike", time());
	
		chance = random(6);
		if( wizardp(me) ) {
			chance = me->query("marks/scll");
		}
//		chance = 2;
		if( me->query_skill("dragonstrike",1) >= 150 ) {
			switch( chance ) {
				case 0:		
					message_vision(WHT"$n"NOR+WHT"冷笑中拆解退让丝毫不乱，俨然无懈可击。\n"NOR, me, target);
					break;		// Normal, NO special effect (SE). 
				case 1:
					message_vision(YEL"$n"NOR+YEL"斜斜滑出三尺，一时间中路空门大开，正是时机！\n"NOR, me, target);
					target->set_temp("annie/beggar/time", time());
					target->set_temp("annie/beggar/6", "cuo");
					break;		// SE: CHUO can do x2
				case 2:
					message_vision(YEL"$n"NOR+YEL"身形乍然一矮，$N"NOR+YEL"掌力掠顶而过，有惊无险地避开这招。\n"NOR, me, target);
					target->set_temp("annie/beggar/time", time());
					target->set_temp("annie/beggar/6", "ban");
					break;		// SE BAN has double rate
				case 3:
					message_vision(YEL"$n"NOR+YEL"觑得亲切，不退反进，借势击向$N！\n"NOR, me, target);
					target->set_temp("annie/beggar/time", time());
					target->set_temp("annie/beggar/6", "yin");
					break;		// SE YIN has double dmg
				case 4:
					message_vision(WHT"$n"NOR+WHT"和身扑上，旋转着但极快疾地欺近$N。\n"NOR, me, target);
					target->set_temp("annie/beggar/time", time());
					target->set_temp("annie/beggar/6", "zjbl");
					break;
				case 5:
					if( target->query_temp("weapon") ) {
						message_vision(YEL"$n"NOR+YEL"不敢冒险，以手中"+target->query_temp("weapon")->name()+NOR+YEL"小心拆解，招架此招。\n"NOR, me, target);
					} else {
						message_vision(YEL"$n"NOR+YEL"不敢冒险，身形凝重，招架此招。\n"NOR, me, target);
					}
					target->set_temp("annie/beggar/time", time());
					target->set_temp("annie/beggar/6", "tiao");	// SE: DISARM
					break;
			}
		}
	} else {
		message_vision(WHT"$n单掌连划三个半圆护住身前，足尖着力，飘身后退。\n"NOR, me, target);
		me->perform_busy(1);
	}
	
	return 1;
}

/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/
