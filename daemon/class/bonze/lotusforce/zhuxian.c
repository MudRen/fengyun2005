// Silencer @ FY4 workgroup. Aug.2004
//	无风自鼓，左手结印，右手法决。背后隐隐有金青光闪动遇神杀神，遇仙诛仙！
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int skill,gin, kee, sen, am1, am2, am3;
	mapping buff;
	
	if(me->query("class")!="bonze")
		return notify_fail("只有兴国禅寺的弟子才能颂『诛仙诀』！\n");

	skill = me->query_skill("lotusforce", 1);
	if(skill < 140) return notify_fail("『诛仙诀』至少需要140级莲华心法！\n");

	if( target != me ) 
	return notify_fail("诛仙诀只能用于自身。\n");

	if (ANNIE_D->check_buff(me,"xg-evil"))
		return notify_fail("你已经在运诛仙诀中了。\n");

	if (ANNIE_D->check_buff(me,"powerup") || ANNIE_D->check_buff(me,"dodgeup")
		|| ANNIE_D->check_buff(me,"parryup"))
		return notify_fail("你已经在使用类似的特技了。\n");
		
	if( (int)me->query("force") < 100 )   return 
		notify_fail("你的内力不够。\n");
	me->add("force", -100);
	
	buff =
		([
			"caster":me,
			"who": me,
			"type":"xg-evil",
			"type2": "powerup",
			"att":"bless",
			"name":"莲华心法·诛仙诀",
			"buff1": "apply/parry",
			"buff1_c":	100,
			"buff2": "apply/dodge",
			"buff2_c":  100,
			"time":  180,
			"buff_msg":HIC"$N"HIC"衣衫无风自鼓，身形竟然是在瞬间膨胀了起来，背后隐隐有金青光闪动，
左手结印，右手法诀并指如剑，深深，呼吸，持剑，向天，天地肃杀！\n" NOR,
		]);
		
	ANNIE_D->buffup(buff);
	if( me->is_fighting() && userp(me)) me->perform_busy(1);
	return 1;
}
