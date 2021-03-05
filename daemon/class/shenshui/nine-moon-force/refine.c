// refine.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
	int skill, force_gain;

	if( me->query("class") != "shenshui" ) {
    	return notify_fail("只有神水宫弟子才能使用『凝神术』的绝技。\n");
    }
	if( me->query_skill("nine-moon-force",1) < 100 ) {
		return notify_fail("『凝神术』需要100级九阴心经。\n");
	}
	skill = me->query_skill("nine-moon-spirit",1);
	if( skill < 100 ) {
		return notify_fail("『凝神术』需要100级姹女神功。\n");
	}
	if( target && target != me ) {
		return notify_fail("『凝神术』只能用来恢复自己的内力。\n");
	}
	if( amount == -1) {
		amount = 50;
	} else if( amount < 50 ) {
		return notify_fail("最少用五十法力。\n");
	}
	if( (int)me->query("mana") < amount ) {
		return notify_fail("你的法力不够。\n");
	}
	if( me->query("force") >= 2*me->query("max_force") ) {
		return notify_fail("你的内力已经是最大值了。\n");
	}
	force_gain = amount*skill/300;
	if( force_gain + (int)me->query("force") > (int)me->query("max_force")*2 ) {
		me->set("force", (int)me->query("max_force")*2);
	} else {
		me->add("force", force_gain);
	}
	me->add("mana", -amount);
	message_vision(BGRN+WHT"$N逆运九阴心经，阵阵似有似无的白气从全身各处飘散而出．．．\n"
				"一丝丝白气迅速凝成雪花，涌入$P的顶心，然後消失无踪。\n" NOR, me);
	if( me->is_fighting() ) {
		me->perform_busy(1);
    }
	me->force_status_msg("all");
    
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
