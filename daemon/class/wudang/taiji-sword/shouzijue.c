// silencer fy4 workgroup

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	
	int skill;
	string msg;
	mapping buff;

	if (me->query("class")!="wudang")
    		return notify_fail("『守字诀』是武当的独有武功。\n");
	
	skill = me->query_skill("taiji-sword",1);
	if( (int)me->query_skill("taiji-sword", 1) < 50 )
		return notify_fail("『守字诀』需要50级的太极剑法。\n");
	
	if (ANNIE_D->check_buff(me,"parryup"))
        	return notify_fail("你已经在使用类似的武功了。\n");
	
	msg = HIC "$N使出『守字诀』，凝神专志，剑圈逐渐缩小，将一套太极剑法使得圆转如意，
严密异常的守住门户，竟是无懈可击。\n"NOR;
	
	buff =
		([
			"caster":	me,
			"who": 		me,
			"type":		"parryup",
			"att":		"bless",
			"name":		"太极剑法·守字诀",
			"buff1":	"perform/taiji_shou",
			"buff1_c":	 1,
			"buff2":	"apply/attack",
			"buff2_c":	-skill,
			"time":  	120,
			"buff_msg":	msg,
		//	"warn_msg":	WHT"『梯云纵』的功效快要结束了。\n"NOR,
		//	"disa_msg":	YEL"你的『守字诀』演练完毕。\n"NOR,
			"special_func":0,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}
