// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>

int exert(object me, object target, int amount)
{
	int level, i, n;

	if( me->query("class")!="taoist" ) {
		return notify_fail("只有三清弟子才能使用此心法！\n");
	}
	if( userp(me) && me->query("scroll/gouyee_heal") < 2 ) {
		return notify_fail("你还没有悟出复苏灵息Ⅱ，需要找到其密籍才行。\n");
	}
	level = me->query_skill("gouyee", 1);
	if( level < 100 || me->query_skill("necromancy",1) < 120 ) {
		return notify_fail("『复苏灵息Ⅱ』需要100级的谷衣心法和120级的三清道术。\n");
	}
	if( !target ) {
		return notify_fail("你要向谁施用此心法？\n");
	}
	if( target->query("possessed") != me || target->query("animated") ) {
		return notify_fail("你只能向你驱使的鬼怪使用此心法。\n");
	}
	if( (int)me->query("gin") <= 400 ) {
		return notify_fail("『复苏灵息Ⅱ』需要400点的精力。\n");
	}
	if( userp(me) ) {
		me->receive_damage("gin", 400);
	}
	message_vision(WHT"$N双手环成一个弯曲的半弧，咬破舌尖，将一口血沫从弧中喷向$n。\n"NOR, me, target);
	call_out("heal_him", 4, me, target, level);
	me->perform_busy(2);
	return 1;
}


int heal_him(object me, object target, int level)
{
	int i, amount;
	amount = 1200;
	if( !me || !target ) {
		return 1;
	}
	if( !target || environment(target) != environment(me) ) {
		tell_object(me, "施法的对象已经不在这里了。\n");
		return 1;
	}
	message_vision(HIY"$n忽而一颤，周身血光隐现，伤口奇迹般消融退去。\n"NOR, me, target);
	target->receive_fulling("kee", amount, me);
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
