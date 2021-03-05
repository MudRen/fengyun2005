// chase.c

#include <ansi.h>

inherit SSERVER;

int curse(object me, object target)
{
	string targetname;
	object room,ob;
	int skill,atman,perp;
	
	if(me->query("class")!="wolfmount")
    		return notify_fail("只有狼山弟子才能使出『蹑杀咒』\n");
	
	if( me->is_fighting() )
		return notify_fail("战斗中无法使用蹑杀咒！\n");
 
    if( (skill=me->query_skill("wolf-curse",1)) < 100 || me->query_skill("cursism",1)< 100)
    	    return notify_fail("蹑杀咒需要１００级天狼血咒和降头术！\n");

	if ( environment(me)->query("no_fly"))
		return notify_fail("此地不能使用蹑杀咒。\n");
	
	if (stringp(me->query_temp("no_move")))
       	return notify_fail(me->query_temp("no_move"));
        	
	if( me->is_ghost())
		return notify_fail("鬼魂无法使用蹑杀咒！\n"); 	
	
	if( !(ob=me->query_temp("chase_target")))
		return notify_fail("你没有下过蹑杀咒或者你下蹑杀咒的人已经死了。\n");
	
	if(! ob->is_character())
		return notify_fail("追踪这个东西？你是不是觉得很无聊？\n"); 
	
	if( ob->is_ghost())
		return notify_fail("人鬼殊途，你不能追踪！\n"); 
	
	if (	environment(ob)->query("no_fight")
		||environment(ob)->query("no_magic")
		||environment(ob)->query("no_death_penalty") 
		|| environment(ob)->query("no_fly"))
			return notify_fail("那个地方好像受到神灵的保护。\n");
	
	if (me->query_temp("in_chase"))
		return notify_fail("你已经在追踪对方了");
	
	if( me->query("kee") <= 100 )
                return notify_fail("你的气血不够！\n");
	me->receive_damage("kee", 100);
	
	if( random(me->query("combat_exp")/20*skill) <ob->query("combat_exp"))
	{
		 message_vision( HIW "$N神色肃然，口中念念有词，但什么事也没发生。\n" NOR, me);
		 return notify_fail("你的降头术还不够熟练。\n");	
	}
			
	message_vision( HIW "$N神色肃然，口中念念有词，身影渐渐地模糊起来 ....\n" NOR, me);
	me->set_temp("in_chase");
	room = environment(ob);
	me->start_busy(2);

	me->start_call_out( (: call_other, __FILE__, "iam_coming", me,ob,room:), 6);
	return 1;
}


void iam_coming(object me,object ob,object room)
{
	
	string id_enemy;
	int eff_shen,shen,skill;
	if (me->is_ghost()) {
		tell_object(me,YEL"你怎么成了鬼了，鬼是无法追踪人的！\n"NOR); 
		me->delete("in_chase");
		return;
	} 
	
	if (me->is_fighting()|| me->is_busy()){
		tell_object(me,YEL"你受到牵制，无法脱身。\n"NOR);
		me->delete("in_chase");
		return;
	}
	
	TASK_D->flying_risk(me);	
	me->move(room);	
	message( "vision", HIW "\n忽然一股青烟从地上冒出，"+me->query("name")+"从烟雾中出现！\n\n" NOR,
		room, ({ me }) );
	if ( environment(ob) != environment(me)) {
		tell_object(me,HIW"太可惜了,"+ob->name()+"刚从这里离开.\n"NOR);
		return;
	}
	me->delete("in_chase");
	me->start_busy(2);
}	

