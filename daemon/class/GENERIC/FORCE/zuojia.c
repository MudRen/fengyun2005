// Silencer @ FY4 workgroup. Aug.2005
/*

云中道人所创的一种奇异功夫。行功时暗运真气，十指轻弹，嘴角微张，头顶冒出丝丝金黄色烟雾，
托住一柄雪白云拂，随意袭敌，疾似闪电流星。回环拂扫，其劲力可摧动万斤巨石。（见梁羽生《武当一剑》）

一种以静制动的玄妙功夫。右手一翻，左手骈指如刃，由右腋下慢慢递出，上下划出
一道线，则对方的几处大穴全都暴露在指力之下，对方不攻自乱，乃是天下第一的防
守功夫。

*/

inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int stage, force, lvl, duration, amount1;
	object obj, *mem;
	string msg, name;
	mapping buff;

	lvl = me->query("cont_quest");
	if( lvl < 5) 	
		return notify_fail("使用『为人作嫁』至少需要连续完成5个天机老人的任务，
你现在只连续完成了"+chinese_number(lvl)+"个。\n");
		
    if (me->is_fighting())
       	return notify_fail("战斗中无法使用『为人作嫁』\n");
    		
	if(!target ) target=me;
	if(target!= me) {
		return notify_fail("『为人作嫁』只能用于自身。\n");
	}
	
	if (ANNIE_D->check_buff(target, "quest_kee"))
		return notify_fail("此人已经在使用类似的心法了。\n");	
	
	if (me->query("force")< 300)
        	return notify_fail("『为人作嫁』至少需要300点真气。\n");
    if (userp(me))	me->add("force",-300);
    
    // STage ADVANCE PERFORM, 
    
    name = "风云·为人作嫁";
    
    if (lvl >= 15)		{lvl = 15; name += "ＩＩＩ";} 
    else if (lvl >=10)	{lvl = 10;name += "ＩＩ";}
    else				{lvl = 5;name += "Ｉ";}
    
    amount1 = me->query("max_kee")* lvl /100;       	
	
	me -> delete("cont_quest");
	
	duration = 1200;
	
	msg = HBRED + HIY"$N暗运真气，十指轻弹，嘴角微张，头顶冒出丝丝金黄色烟雾。\n"NOR;
		
	buff =
		([
			"caster": me,
			"who":  target,
			"type": "quest_kee",			// Just annie_d changes
			"att":	"bless",
			"name":	name,
			"buff1":"kee",
			"buff1_c":amount1,		
			"time":  1200 ,
			"buff_msg": msg,
			"special_func":1,
		]);
		
    ANNIE_D->buffup(buff);
	me->perform_busy(1);
	return 1;
}



