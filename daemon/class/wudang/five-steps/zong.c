//	 Silencer@fy4 workgroup

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	int skill, add_agi;
 	string msg;
 	mapping buff;
 	
 	skill = (int) me->query_skill("five-steps",1);
 	 	
 	if (me->query("class") != "wudang")
  		return notify_fail(WHT"你不是武当弟子，不能使用『梯云纵』。\n"NOR);

	if( !skill || (skill < 100))
  		return notify_fail(WHT"演变『梯云纵』需要100级的五行身法！\n"NOR);
 	
 	if (!target)	target = me;
 	
 	if (target!= me ) 
 		return notify_fail(WHT"『梯云纵』只能用于自身。\n"NOR);
 	
 	if (ANNIE_D->check_buff(me, "agiup")|| ANNIE_D->check_buff(me,"boostcurse"))
        	return notify_fail("你已经在使用类似的武功了。\n");
        
        if( me->query("force") < 100 )     
        	return  notify_fail("『梯云纵』需要100点内力。\n");   	
	me->add("force", -100);
 	
 	add_agi = skill / 20;		// 0-20
 	
 	msg = BGRN + HIG"
$N提气纵身，气凝丹田，右脚在左脚脚背一踏，倏然间身形又凭空拔起三丈，
跟着身体向前飘行两丈，然后稳稳落地，正是武当绝技『梯云纵』！\n\n"NOR;

	buff =
		([
			"caster":	me,
			"who": 		me,
			"type":		"agiup",
			"att":		"bless",
			"name":		"五行步法·梯云纵",
			"buff1":	"apply/agility",
			"buff1_c":	add_agi,
			"time":  	300,
			"buff_msg":	msg,
			"disa_msg":	YEL"你施展完毕『梯云纵』，稳住身形。\n"NOR,
		]);
	ANNIE_D->buffup(buff);
 	       	
	return 1;
}
