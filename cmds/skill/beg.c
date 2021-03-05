// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp,lvl;

	object where = environment(me);
    
    
    if (userp(me) && me->query("class")!="beggar" )
       	return notify_fail("只有丐帮弟子才能乞讨！\n");

	if (userp(me))
    	return notify_fail("南宫灵整顿帮纪，暂时不准丐帮弟子胡乱乞讨了！\n");
    
	if( environment(me)->query("no_beg")
	 || environment(me)->query("no_fight"))
	 	return notify_fail("这里不是适合丐帮弟子讨饭的地方！\n");

	if( me->query_temp("begging") )
		return notify_fail("你已经在向别人乞讨了！\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
		notify_fail("指令格式：beg <某物> from <某人>\n");

	if ( userp(me) && ((int)me->query_skill("begging",1) < 25))
		return notify_fail("乞讨至少需要２５级乞讨之术。\n");
	
	victim = present(who, environment(me));
	if( !victim || victim == me) return notify_fail("你想乞讨的对象不在这里。\n");

	if( !living(victim) || !objectp(victim))
		return notify_fail("你要向谁乞讨？\n");

        if ( (vtfam = victim->query("family")) && vtfam["family_name"] == "丐帮" )
                return notify_fail("你不能向本帮弟子乞讨！\n");

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("不能向管理人员乞讨。\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, victim)) {
		if (stringp(victim->query("NO_KILL")))
			return notify_fail(victim->query("NO_KILL"));
		if (stringp(victim->query("NO_PK")))
			return notify_fail(victim->query("NO_PK"));	
		else 
			return notify_fail("你无法向此人乞讨。\n");
	}
	
	if( me->is_fighting() )
                return notify_fail("不可以一边打架一边乞讨！\n");

	if( victim->is_fighting() )
                return notify_fail(victim->name() + "正在打架，没空理你！\n");

	if( !ob = present(what, victim) ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "身上看起来没有什麽让你感兴趣的东西。\n");
		ob = inv[random(sizeof(inv))];
	}

	if (ob->query("equipped") || ob->query("no_drop") || ob->query("owner"))
		return notify_fail(victim->name()+"好象不会施舍给你任何东西似的。\n");
        
        if(me->query("sen") <= 100 && userp(me))
            	return notify_fail("乞讨需要耗费一定的心神（100）。\n");
        if (userp(me))
        	me->add("sen",-100);

	lvl = me->query_skill("begging",1);
	
	// 200 * 200 + 55*55*55/3 = 95450
	// 60*1000 + score + bellicosity
	// The formula doesn't really make sense... 
	// Let's just say, you can improve your chance, but whom you can beg easily is pure chance.
			
	sp = (lvl * lvl + me->query_kar()* me->query_kar()* me->query_kar()/3)/10;
        dp = victim->query_cps()*1000 
        	+ victim->query("score") + victim->query("bellicosity");
        
	tell_object(me, "你一脸可怜巴巴的样子，慢慢地向" + victim->name() + "走过去，伸出双手，想要"
			+ ob->query("unit") + ob->name() +"……\n\n");
	tell_object(victim, me->name() + "一脸可怜相，向你慢慢走过来，伸出手，说道：" + RANK_D->query_respect(victim) + "行行好，给我"
			+ ob->query("unit") + ob->name() + "吧……！\n\n");
	message("vision", "只见" + me->name() + "装出可怜巴巴的样子，慢慢地向"
		+ victim->name() + "走过去，\n伸出双手，说道："
		+ RANK_D->query_respect(victim) + "，行行好吧……\n\n", environment(me), ({ me, victim }) );

	if (wizardp(me))
		tell_object(me, "the begging chance is " + sp + " vs " + dp + "\n");
	me->set_temp("begging", 1);
	call_out( "compelete_beg",random(3)+1, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	object ob1;

	if (!me)	return;
		
	me->delete_temp("begging");
	if(!victim) {
                tell_object(me, "太可惜了，你要乞讨的人已经不见了。\n");
                return;
        }
	if( environment(victim) != environment(me) ) {
		tell_object(me, "太可惜了，你要乞讨的人已经走了。\n");
		return;
	}
// exp limit to stop beggar dummies
	if (userp(me) && victim->query("combat_exp")>me->query("combat_exp")*10) {
		tell_object(me,victim->name()+"不屑地看了你一眼说：“再去练练吧。“\n");
		return;
	}

	if (!ob || !present(ob, victim)) {
		tell_object(me, "你想要的东西已经不在"+victim->name()+"身上了。\n");
		return;
	}
	
// not a human being
	if(victim->query("race")!="人类") {
		tell_object(me,victim->name()+"根本就无动于衷！\n");
		return;
	}
	if( living(victim) && (random(sp+dp) > dp) && ob->move(me))
	{
		message_vision("$N看着$n的可怜样，叹了口气，丢给$n一"
			+ ob->query("unit") + ob->name() + "。\n",victim,me);
		me->start_busy(3);
	}
	else
	{
		if( random(sp+dp) > dp/2 ) {
                	message_vision("$N扭过头去，对$n理都不理。\n", victim,me);
                	me->start_busy(3);
			return;
		}
		
		message_vision("$N狠狠地瞪了$n一眼，喝道：穷叫化子！真讨厌！不打不行了！\n", victim,me);
		if(!environment(victim)->query("no_fight"))
			victim->fight_ob(me);
		me->start_busy(3);
	}
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	beg <东西> from <他人>[0m
[0;1;37m────────────────────────────────[0m   

这是一个丐帮专用的指令，用来向他人乞讨物品，乞讨的成功率与乞讨者
的运气、乞讨之术的高低、以及双方的江湖经验相关。
不过，自南宫灵接掌帮主之位后，整顿帮纪，不准丐帮弟子胡乱乞讨了。

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}
