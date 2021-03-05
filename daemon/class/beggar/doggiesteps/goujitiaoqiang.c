// silencer@fy
#include <ansi.h>
#include <combat.h>
#include <command.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, enhance,duration;
	object room;
	mapping buff;
	
	if(me->query("class")!="beggar")
    	return notify_fail("你又不是叫花子，使这种招数忒丢身份了吧。\n");

	extra = me->query_skill("doggiesteps",1);
	if ( userp(me) && extra < 200) 
		return notify_fail("『狗急跳墙』需要200级的野狗步法！\n");

	enhance = me->query_skill("begging",1);
	if ( userp(me) && enhance < 160) 
		return notify_fail("『狗急跳墙』需要160级的乞讨之术！\n");

	duration = me->query("timer/pfm/gb_gjtq")-time() + 900;
    if (duration>0)
    	return notify_fail("你还需要等待"+(duration/60)+"分钟左右才能再次使用『狗急跳墙』\n");
    		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『狗急跳墙』只能对战斗中的对手使用。\n");
	
	room = environment(me);
	
	me->set("timer/pfm/gb_gjtq",time());
	
// 	Let's calculate escape chance of same agility opponents
//	It shall be 1- 50%*50%*50% = 87.5%, a very good value
//	So the penalty of that 12.5% will be .... death.
//	if 1/3 chance to escape, 1- 2/3*2/3*2/3 = 70%
//	it needs a timer

	message_vision(HIW"\n$N凌空一跳，身形如被逼急的野狗，双脚作势向$n踢出！
将到未到之时，一个跳步向左窜去。\n"NOR,me,target);
	
	me->delete_temp("marks/escape");
	me->add_temp("no_flee_msg",1);
	GO_CMD->do_flee(me);
	me->add_temp("no_flee_msg",-1);
	
	if (environment(me) != room) {
		message("vision",YEL"\n"+target->name()+YEL"一个措手不及，让"
				+me->name()+YEL"从身边溜了过去。 \n"NOR,room,({me,target}));
		tell_object(target,YEL"你一个措手不及，让"+me->name()+YEL"从身边溜了过去。 \n"NOR);
		return 1;
	} else
//		message_vision(HIR"$N身形未动，却正好挡住了$n的去路。 "NOR,target,me);		
	msg = YEL "$N气急败坏，趁势朝$n的$l踹去。" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"踢伤");
	
	if (me->is_busy())	return 1;
	
	message_vision(HIW"\n$N见不是路，疾出双手摆个花架，乘机向右遁逃。\n"NOR,me,target);
	me->delete_temp("marks/escape");
	me->add_temp("no_flee_msg",1);
	GO_CMD->do_flee(me);
	me->add_temp("no_flee_msg",-1);
	if (environment(me) != room) {
		message("vision",YEL"\n"+target->name()+YEL"一个措手不及，让"
				+me->name()+YEL"从身边溜了过去。 \n"NOR,room,({me,target}));
		tell_object(target,YEL"你一个措手不及，让"+me->name()+YEL"从身边溜了过去。 \n"NOR);
		return 1;
	} else
//		message_vision(HIR"$N虚空拍出一招，把$n打了下来。"NOR,target,me);
	msg = YEL "$N虚招化实招，双脚一前一后连环踢出！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"踢伤");
		 
	if (me->is_busy())	return 1;
		
	message_vision(HIW"\n$N无计可施，舍身向$n扑去，却往$n身下一滚，不战而逃！\n"NOR,me, target);
	me->delete_temp("marks/escape");
	
	me->add_temp("no_flee_msg",1);
	GO_CMD->do_flee(me);
	me->add_temp("no_flee_msg",-1);
	if (environment(me) != room) {
		message("vision",YEL"\n"+target->name()+YEL"一个措手不及，让"
				+me->name()+YEL"从身下溜了过去。 \n"NOR,room,({me,target}));
		tell_object(target,YEL"你一个措手不及，让"+me->name()+YEL"从身下溜了过去。 \n"NOR);
		return 1;
	} else
//		
	message_vision(HIR"\n$N双掌齐出，$n只觉气血一滞，便如撞上了一堵气墙。\n"NOR, target, me);

	me->perform_busy(2);	
	return 1;
}

