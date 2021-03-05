// L150: 聚寒：聚水成冰，在梅雨潭运内力聚成寒冰，每15分钟得到一片，heal self 2次
// ice 实际只是摆设，mark在使用者身上

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me,object target)
{
    string msg,name;
	object ice;
	int duration, amount, dorm, skill, num;
	
	if(me->query("class")!="legend" && userp(me))
		return notify_fail("只有铁雪山庄的嫡传弟子才能够使用聚寒诀。\n");

 	skill = me->query_skill("qidaoforce",1);
 	dorm = me->query_skill("dormancy",1);
 	
 	if( skill <150)
		return notify_fail("『聚寒诀』需要150级的棋道心法。\n");
 	
 	target=me;
 	
 	/*
 	set("resource/water", 1);
	set("liquid/container", "梅雨潭");
	set("liquid/name","梅雨潭水");
 	*/
 	 	
 	if (!environment(me)->query("resource/water"))
 		return notify_fail("『聚寒诀』需要在水源旁方能施展。\n");
 	
 	if (!stringp(name=environment(me)->query("liquid/name")))
 		name = "水花";
 	 	
 	if (me->is_fighting())
 		return notify_fail("战斗中不能施展此心法。\n");	
 		
 	duration = me->query("timer/legend_juhan")-time() + 900;
    if (duration>0)
       	return notify_fail("你需要等待"+(int)(duration/60+1)+"分钟左右才能够再次使用聚寒诀。\n");
 	
 	msg = WHT"$N倒运内力，掌中散出丝丝寒气，"+ name + "溅在手心，瞬间凝结成冰。\n"NOR;
    
    amount = 1000;
    num = 2;
    
    if (dorm >= 270) {amount = 3000; num = 3;}
	else if (dorm > 220) {amount = 2000; num = 2; }  
    	         
   		seteuid(getuid());
        ice = new("/obj/specials/legend/ice");
        
        if (!ice->move(me)) {
        	destruct(ice);
        	return 1;
        }
        
        ice->set("juhan_owner",me);
        ice->set("amount",amount);
        me->set("timer/legend_juhan",time());
        me->set("marks/legend_juhan",num);
        message_vision(msg, me);
	
	me->perform_busy(1);
	       
	return 1;       
}
