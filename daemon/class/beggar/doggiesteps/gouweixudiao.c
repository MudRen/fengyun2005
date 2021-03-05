#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *team;
	int i, skill, duration;
	mapping buff;

	skill = me->query_skill("doggiesteps",1);
	if( skill < 100 ) {
		return notify_fail("『狗尾续貂』至少需要100级野狗步法。\n");
	}
	skill = me->query_skill("begging",1);
	if( skill < 80 ) {
		return notify_fail("『狗尾续貂』至少需要80级乞讨之术。\n");
	}
	if( ANNIE_D->check_buff(me, "beggardoggie") ) {
		return notify_fail("你已经在使用『狗尾续貂』了。\n");
	}
	buff =
		([
			"caster":me,
			"who": me,
			"type":"beggardoggie",
			"att":"bless",
			"name":"野狗步法·狗尾续貂",
			"time": 120,
			"buff_msg":YEL"$N双腿半曲半伸，双掌如封如攻，矫健灵活之态，正是狗尾续貂一势。\n"NOR,
		]);

	ANNIE_D->buffup(buff);
	if( userp(me) && me->is_fighting() ) {
		me->perform_busy(2);
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
