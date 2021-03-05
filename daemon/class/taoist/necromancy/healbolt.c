// healbolt.c

#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int amount, cost, lvl, i, j, num, duration;
	object *enemy, *team1, team;
	int ann;

	if( me->query("class") != "taoist" ) {
		return notify_fail("只有三清宫的弟子才能够使用三清道术。\n");
	}
	lvl = me->query_skill("necromancy",1);
	if( lvl < 80 ) {
		return notify_fail("『白云之箭』需要80级的三清道术！\n");
	}
	if( me->query_skill_mapped("force") != "gouyee" ) {
		return notify_fail("三清道术需使用谷衣心法的运转法门。\n");
	}
	team = me->query_team();
	if( !sizeof(team) ) {
		return notify_fail("『白云之箭』只可在队伍中使用。\n");
	}
	duration = me->query("timer/pfm/sq_heal") - time() + 10;
	if( duration > 0 ) {
		return notify_fail("你精气已竭，需等待"+ duration +"秒才能够再次使用『白云之箭』。\n");
	}
	team1 = filter_array(team, (: present($1,environment($2)) :), me);
	num = sizeof(team1);
	if( num < 2 ) {
		return notify_fail("你身边没有队友，用这招不是吃力不讨好么！\n");
	}
	if( lvl <= 120 ) {
		ann = 5;
	} else {
		ann = 10;
	}
	// self -800 ~ 2000kee, everyone else + 800~2000 kee;
	amount = lvl * ann;
	if( me->query("kee") < amount) {
		return notify_fail("你的气血不够施此法术。\n");
	}
	if( me->query("mana") < 300 ) {
		return notify_fail("『白云之箭』至少需要300法力。\n");
	}
	if( userp(me) ) {
		me->add("mana", -300);
	}
	msg = BBLU + HIW "
$N口中喃喃地念著咒文，左手一挥，一道淡淡的白烟袅袅升起，在空中盘旋！\n\n" NOR;				
	message_vision(msg, me);
	me->set("timer/pfm/sq_heal", time());
	me->set_temp("last_damage_from","使用白云之箭不慎身亡。\n");
	me->receive_damage("kee", amount);
	for( i = 0; i < num; i++ ) {
		if( !COMBAT_D->legitimate_buff(me, team1[i]) ) {
			continue;
		}
		if( team1[i] == me) {
			continue;
		}
		if( team1[i]->query("kee") < team1[i]->query("max_kee") ) {
			team1[i]->receive_fulling("kee", amount, me);
			tell_object(team1[i], WHT"你的伤势奇迹般地开始愈合。\n"NOR);
			if( team1[i]->is_fighting() ) {
				enemy = team1[i]->query_enemy();
				for( j = 0;j < sizeof(enemy); j++) {
					if( !enemy[j]->is_fighting(me) ) {
						enemy[j]->kill_ob(me);
						me->kill_ob(enemy[j]);
					}
				}
			}
		}
	}
	me->perform_busy(2);
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
