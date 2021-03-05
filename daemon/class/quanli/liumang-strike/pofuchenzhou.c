// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce;

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	extra = me->query_skill("unarmed");

	if ( extra < 300) return notify_fail("你的流氓神拳还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［破釜沉舟］只能对战斗中的对手使用。\n");
	me->add("force_factor",extra/3);
	orforce = (int) me->query("force");
	me->add("force",extra/3*100);
	me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
	msg = HIY  "$N使出独步天下的［流氓神拳］，一招［破釜沉舟］，略带一丝惋惜之色向$n的全身要穴攻出！\n" NOR;
	message_vision(msg,me,target);
	msg = HIY  "第一拳------笑问七剑一指仙！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "第二拳------叶落枫舞二穿山！！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "第三拳------袖里风云三点头！！！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "第四拳------回首太白四气刀！！！！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "第五拳------化月孤心五看地！！！！！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "第六拳------茫茫秋水六荒天！！！！！！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "第七拳------笑问叶落看风云！！！！！！！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	msg = HIY  "最后一拳------回首化月望秋水！！！！！！！！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	me->start_busy(5);
	me->set("force_factor",0);
	me->set("force", orforce);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
	return 1;
}
