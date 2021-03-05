/* // Silencer @ FY4 workgroup. Aug.2004
	『雨露』〔dart)：昔日伊贸忍者为刺杀强敌，在土中潜伏三天
三夜，借暴雨之声势无声无息地射出暗器，其形如丝，其轻如雾，故得名
为雨露。（需150级）*/
// Basically, it does some damage before fight, without aggro.

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	if((int) me->query_skill("ninjitsu",1) < 150)
    	return notify_fail("雨露需要150级的忍术！\n");
	
	if(environment(me)->query("no_death_penalty"))
		return notify_fail("你无法在这里使用飞镖。\n");
	if( me->query_temp("ninjitsu_dart"))
       	return notify_fail("你正在狙击之中，不可分心。。\n");
	if( me->query("atman") < 200 )
		return notify_fail("需要200点的灵力！\n");
        
	write("你要狙杀谁？");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob,room,here;
	int lvl,extra,delay,dis,x,y,z;
	int my_exp, your_exp, your_perp, my_skill;
	
	if( !name || name=="" ) {
		write("终止狙击。\n");
		return;
	}

	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_real_living(name);
	if ( !ob) 
	{
		tell_object(me,"你要狙击的对象不存在。\n");
		return;
	}
	
	if (!COMBAT_D->legitimate_kill(me, ob)) {
		if (stringp(ob->query("NO_KILL"))){
			tell_object(me,ob->query("NO_KILL"));
			return;
		}
		if (stringp(ob->query("NO_PK"))) {
			tell_object(me, ob->query("NO_PK"));
			return;
		}
		else {
			tell_object(me,"你不能暗杀此人。\n");
			return;
		}
	}
	
	my_exp=me->query("combat_exp");
	your_exp=ob->query("combat_exp");
	
	if (my_exp > 10* your_exp) {
		write("暗杀这么差劲的对手太失身分了。\n");
		return;
	}
	
	if( me->query("atman") < 200 ) {
		write("雨露需要200点的灵力！\n");
		return;
	}
	if (userp(me))	me->add("atman", -200);
		
	lvl = me->query_skill("magic");
	
	// (150 + 435)*1.5 = 585 - 1160.. hmm, 巡捕专用机能
	
	extra = lvl + F_LEVEL->get_level(me->query("combat_exp"));
	extra = extra + random(extra);
	
	delay = 6;
	
	delay = delay+random(delay);
	
    message_vision( HIY "$N闭目凝神，似乎在计算着什么。。\n" NOR, me);
	
	room=environment(ob);
	if(!room||room->query("no_magic")||room->query("no_fight")) 
	{	
		tell_object(me,HIB"你无法确定敌人的位置。\n"NOR);
		return;
	}
		
	here=environment(me);
	x=room->query("coor/x")-here->query("coor/x");
	y=room->query("coor/y")-here->query("coor/y");
	z=room->query("coor/z")-here->query("coor/z");
	dis=x*x+y*y+z*z;
	if(dis>lvl*2)	// 435* 2 = 870
	{
       	tell_object(me,HIB"依你此时的功力，还无法狙击如此遥远的敌人。\n"NOR);
		return;
	}
	me->set_temp("ninjitsu_dart",1);	
	call_out("throwing",delay,me,ob,room,extra);
	extra = COMBAT_D->magic_modifier(me, ob, "kee", extra);
	me->start_busy(delay/2);
	
	return ;
}

int throwing(object me, object ob, object room,int extra)
{	
	string msg;
	int my_exp,your_exp,your_perp, my_skill;
	me->delete_temp("ninjitsu_dart");
	
    message_vision(HIR"$N微睁双目低喝一声，袍袖轻拂，一枚飞镖顿如流星闪电般划过长空。。。\n"NOR,me);
	
	my_exp=me->query("combat_exp");
	your_exp=ob->query("combat_exp");
		
	if(present(ob,room))
	{
        message_vision(HIR"$N眼前一花，一枚飞镖竟已呼啸而至！！\n"NOR,ob);
		if(userp(ob))
			ob->delete_temp("been_darted");
		if (random(your_exp) > random(my_exp *2)
				|| ob->query_temp("been_darted")+300>time())
	        {
			message_vision(HIG"$N似乎早有准备,两指一摒,啪地将飞镖夹住.\n"NOR,ob);
			msg=TASK_D->locate_obj(ob,me->query("id"));
			tell_object(ob,"根据飞镖的来势，你判断出，袭击你的"+msg+"。\n");		
			tell_object(me,"不好,你的飞镖被对方破了。\n");
			return 1;
		}
			
		ob->set_temp("damaged_during_attack",1);
		msg=TASK_D->locate_obj(ob,me->query("id"));
		tell_object(ob,"根据飞镖的来势，你判断出，袭击你的"+msg+"。\n");		
		tell_object(me,"看来你的狙击成功了。\n");
		
		ob->receive_wound("kee",extra,me);
		COMBAT_D->report_status(ob);
		ob->set_temp("last_damage_from","中雨露而死。\n");
		ob->set_temp("been_darted",time());
		return 1;
	}
    	message("vision",HIW"一枚飞镖吧嗒一声掉在你面前。\n"NOR,room);
    	tell_object(me,"非常遗憾，你的狙击无功而返。。。\n");
	return 1;
}
	
	
