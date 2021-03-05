// sillencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int duration, i;
    	object *inv, herb;
    	
    	if(me->query("class")!="knight")
    		return notify_fail("只有快活林弟子才能够使用『春去也』。\n");

	if (me->query_skill("dream-herb",1)<170)
		return notify_fail("『春去也』需要170级的云梦五花锦。\n");

	if (!target) target = me;
	
	if (me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法使用『春去也』\n");
	
	if (userp(me) && !userp(target))
		return notify_fail("『春去也』只能对非NPC使用。\n");
			
	duration = me->query("timer/lifesave_cast") + 3600 - time();
	
	if (duration > 0)
		return notify_fail("『春去也』每一小时只能施用一次（距离下次使用还有"+ duration/60 + "分钟）\n");
	
	if (target!=me) {
		inv= all_inventory(me);
		i = sizeof(inv);
		while (i--) {
			if (inv[i]->query("name") == BLU"还魂草"NOR && inv[i]->query("revive"))
				herb = inv[i];
		}
		if (!herb)
			return notify_fail("需要借助还魂草的药力才能对其他人施『春去也』\n");
		tell_object(me,"你暗运内力，将还魂草化开在掌心。\n");
		herb->add_amount(-1);
	}
	
	if( (int)me->query("force") < 400 )
		return notify_fail("『春去也』需400点的内力！\n");

	if( (int)me->query("kee") < 250 )
		return notify_fail("『春去也』需250点的气血！\n");

	if (userp(me)){
		me->add("force", -400);
		me->add("kee", -250);
	}		
			
	if (target == me) {
	message_vision(HIG"\n
$N"HIG"从怀中抽出数根银针，插入自己头顶穴道，身形突然快速旋转起来，
面上血色全部褪去，脸色由白变绿，由绿转黄，再由黄返红，一瞬间
竟变了十数次，终于恢复了常态。\n\n"NOR,me);
	} else {
	message_vision(HIG"\n
$N"HIG"从怀中抽出数根银针，插入$n"HIG"头顶穴道，身形突然快速旋转起来，
大喝一声击在$n"HIG"顶门。$n"HIG"面上血色全部褪去，脸色由白变绿，由绿转黄，
再由黄返红，一瞬间竟变了十数次，终于恢复了常态。\n\n"NOR,me,target);
	}	
	target->set("timer/lifesave",time());
	target->set("pfm/chunquye_pw",1);	// 20+1, 21% chance
	tell_object(target,WHT"『落花流水春去也』将持续"+chinese_number(60)+"分钟。\n"NOR);
	me->set("timer/lifesave_cast",time());	
	
	return 1;
}
