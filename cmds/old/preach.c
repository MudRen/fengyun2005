// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;

	object where = environment(me);
        if(me->query("class") != "swordsman")
                return notify_fail("只有熟读道德经，令人敬仰的剑客才可以布道！\n");
	if( environment(me)->query("no_preach"))
		return notify_fail("这里不适合你布道！\n");

	if( me->query_temp("preaching") )
		return notify_fail("你正在布道！\n");

	if( !arg || sscanf(arg, "%s about %s", who, what)!=2 ) return
		notify_fail("指令格式：preach <某人> about <某物>\n");
	if(me->query("sen") < 21)
		return notify_fail("你的神不够！\n");
	victim = present(who, environment(me));

	if( !victim || victim == me) return notify_fail("你想布道的对象不在这里。\n");

	if( !living(victim) || !objectp(victim))
		return notify_fail("你要向谁布道？\n");

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail(victim->name()+"不会听你布道的。\n");
	if( me->is_fighting() )
                return notify_fail("不可以一边打架一边布道！\n");

	if( victim->is_fighting() ) 
                return notify_fail(victim->name() + "正在打架，没空理你！\n");
        if((int)me->query_skill("daode",1) < 25 )
                return notify_fail(victim->name()+"好象不会理会你似的。\n");
	if( !ob = present(what, victim) ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "身上看起来没有什麽让你值得布道东西。\n");
		ob = inv[random(sizeof(inv))];
	}

	if ( ob->query("equipped") || ob->query("no_drop") || ob->query("owner"))
		return notify_fail(victim->name()+"好象不会理会你似的。\n");

	sp = (int)me->query_skill("daode",1) * (int)me->query_skill("daode",1) 
	 + (int)me->query_cps() * (int)me->query_cps() * (int)me->query_cps() ;
	if( sp < 5000 ) return notify_fail("你还没有到达布道的阶段。\n");
	dp = (int) victim->query("score")-(int)victim->query("bellicosity") + 
	(int)victim->query_cps() * (int)victim->query_cps() * (int)victim->query_cps() * (int)victim->query_cps() +
	(int)victim->query_int()*(int)victim->query_int()*(int)victim->query_int();
	tell_object(me, "你庄严地向" + victim->name() + "诉说身揣"
			+ ob->query("unit") + ob->name() +"的种种坏处...\n\n");
	tell_object(victim, me->name() + "满面庄严，向你耐心诉说道：这位" + RANK_D->query_respect(victim) + "，人生如梦，放弃" 
			+ ob->query("unit") + ob->name() + "吧 ...！\n\n");
	message("vision", "只见" + me->name() + "满面庄严，神情严肃，\n向" 
		+ victim->name() + "不厌其烦地布道着．．．",environment(me), ({ me, victim }) );

	me->set_temp("preaching", 1);
	me->receive_damage("sen",20);
	call_out( "compelete_preach",random(3)+1, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_preach(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	object ob1;

	me->delete_temp("preaching");
        if(!victim) {
                tell_object(me, "太可惜了，你给布道的人已经不见了。\n");
                return;
        }
	if( environment(victim) != environment(me) ) {
		tell_object(me, "太可惜了，你给布道的人已经走了。\n");
		return;
	}

	if(!victim->query("spi")) {
		tell_object(me,victim->name()+"对你的布道无动于衷！\n");
		return;
	}
	if( living(victim) && (random(sp+dp) > dp) && ob->move(environment(me))) 
	{
		message_vision("$N听着$n的布道，深有感触，一激动，将一" 
				+ ob->query("unit") + ob->name() + "丢在地下。\n",victim,me);

//		me->improve_skill("begging", random(me->query("int")));
//		me->add("potential",1);
//		me->add("combat_exp",1);
		me->start_busy(1);
	} 
	else 
	{
		if( random(sp+dp) > dp/2 ) {
                message_vision("$N象一块顽石般，对$n的布道毫不理会。\n", victim,me);
                me->start_busy(3);
			return;
		}
		else
		message_vision("$N狠狠地瞪了$n一眼，喝道：真讨厌！去死了吧！\n", victim,me);
		if(!environment(victim)->query("no_fight"))	
		victim->fight_ob(me);
		me->start_busy(3);
	}
}

int help(object me)
{
write(@HELP
指令格式 : preach <某人> about <某物>

HELP
    );
    return 1;
}
