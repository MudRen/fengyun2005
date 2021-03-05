
#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me,object target,int amount)
{
        int level, fix, duration, add;
        mapping buff;
        string msg;

		if(me->query("class")!="legend" && userp(me))
			return notify_fail("只有铁雪山庄的弟子才能够使用聚心诀。\n");

	 	level = me->query_skill("dormancy",1);
	 	if( level < 150 || me->query_skill("qidaoforce",1)< 150)
			return notify_fail("『聚心诀』需要150级的息若纳气和150级棋道心法。\n");
              
        if (target && target!= me)
 			return notify_fail("此心法只能用在自己身上。\n");
             
        if (level< 200)
        	duration = me->query("timer/pfm/tx_juxin")-time() + 180;
        else
        	duration = me->query("timer/pfm/tx_juxin")-time() + 150;
        
        if (duration>0)
        	return notify_fail("你还需要等待"+(int)(duration)+"秒钟左右才能够再次使用聚心诀。\n");
        
		me->set_temp("marks/pfm/tx_juxin",time());
		me->delete_temp("last_damage_from");
		message_vision(HIR"$N运内力护住经脉，脸上紫气大盛，一声大喝，更是元气充沛，淋漓浑厚。\n"NOR, me);	  
		tell_object(me,RED"你的伤势愈合了一部分。\n"NOR, me);	
	
		amount = 30;	
		amount = COMBAT_D->magic_modifier(me, me, "kee",me->query("max_kee")*amount/100);

		me->receive_fulling("kee",amount);
		me->receive_curing("kee",me->query("max_kee"),me);
			
		amount = 50;
		amount = me->query("max_force")*amount/100 ;
		if (me->query("force") + amount < me->query("max_force")*2)
				me->add("force", amount);	
			else
				me->set("force", me->query("max_force")*2);	

		me->force_status_msg("force");
		me->set("timer/pfm/tx_juxin",time());
		return 1;
}