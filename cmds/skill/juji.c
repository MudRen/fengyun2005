#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int main(object me, string arg)
{
	object obj;
	int skill, i, count, myexp, yourexp, lvl;
	string gender,msg;
	
	if (me->query("class")!="beggar")
		return notify_fail("只有丐帮弟子才能使用偷袭。\n");
	
	lvl = me->query_skill("begging",1);
	if (lvl < 90)
		return notify_fail("狙击至少需要90级的乞讨之术。\n");
		
	if (environment(me)->query("no_fight"))
		return notify_fail("这里禁止战斗。\n");

	if (! arg || ! objectp(obj = present(arg, environment(me))))
		return notify_fail("你想偷袭谁？\n");

	if (! obj->is_character())
		return notify_fail("看清楚一点，那并不是生物。\n");

	if (obj->is_fighting(me))
		return notify_fail("你已经在战斗中了，还想偷袭？\n");

	if (!living(obj))
		return notify_fail(obj->name() + "都已经这样了，你还用得着偷袭吗？\n"); 

	if (obj == me)
		return notify_fail("偷袭自己？别这么想不开。\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, obj)) {
		if (stringp(obj->query("NO_KILL")))
			return notify_fail(obj->query("NO_KILL"));
		if (stringp(obj->query("NO_PK")))
			return notify_fail(obj->query("NO_PK"));	
		else 
			return notify_fail("你无法偷袭此人。\n");
	}
		
	if (me->is_busy())
		return notify_fail("你正忙着，不能偷袭。\n");

	if (obj->query_temp("juji_alert")+ 60 > time())
		return notify_fail("对方正处于高度警惕之中，无法偷袭成功。\n");	
		
	gender = obj->query("gender")=="男性" ? "他" : "她";
	
	tell_object(me, CYN"你悄悄走到"+obj->name()+CYN"背后，飞身纵起，猛然向"+gender+"扑去！"NOR);
	tell_object(obj, BLU"你身后忽然跳出一个人影，倏然向你发起攻击！\n" NOR);
	
	message("vision",CYN""+me->name()
		+CYN"悄悄走到"+obj->name()+CYN"背后，飞身纵起，猛然向"
		+obj->name()+CYN"扑去！" NOR, environment(me), ({me, obj}));

	skill = me->query_skill("betting",1);
	myexp = me->query("combat_exp");
	yourexp = obj->query("combat_exp");
	
	count = me->query_agi()/10;
//	me->ccommand("kill "+obj->get_id());
	
	me->kill_ob(obj);
	obj->kill_ob(me);
	i = 0;
	
	if ( myexp/2 + random(myexp*4) <  yourexp)
	{
		message_vision(YEL"$N不知何时却已转到了$n的身后，$n扑了个空。\n"NOR,obj,me);
	} else
	{
		while (count--) { 
			if (me->is_busy())	continue;
			msg = BLU"阴影中飞出第"+chinese_number(i+1)+"招\n"NOR;
			me->add_temp("apply/damage",lvl);
			COMBAT_D->do_attack(me,obj,TYPE_PERFORM,msg);
			me->add_temp("apply/damage",-lvl);
			i++;
		}
	}
	
	me->perform_busy(1);
	if (obj)
		obj->set_temp("juji_alert",time());
	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	juji <人物>[0m
[0;1;37m────────────────────────────────[0m   
 
狙击，其实就是趁人不备的偷袭，为丐帮弟子专用。狙击的成功率与
狙击者的经验相关，狙击次数=自身速度/10

狙击至少需要90级的乞讨之术。

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}
