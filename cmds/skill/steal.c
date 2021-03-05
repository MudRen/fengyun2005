// steal.c


#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string what, who;
        object ob, victim, guard;
        int sp, dp;

	if(me->query_skill("stealing",1) < 25 )
		return notify_fail("行窃至少需要２５级的妙手空空之技。\n");

        if( environment(me)->query("no_fight"))
                return notify_fail("这里禁止行窃。\n");
                
	if (guard=present("police",environment(me))) {
		message_vision(guard->query("name")+"对$N说：鬼鬼祟祟地想干什么？\n",me);
		return 1;
	}
	
	if (me->is_fighting() || me->is_busy())
		return notify_fail("你现在正忙，等会儿再下手吧。\n");
		
	if( me->query_temp("stealing") )
    	return notify_fail("你已经在找机会下手了！\n");

        if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
                notify_fail("指令格式：steal <物品> from <人物>\n");

        victim = present(who, environment(me));
        if( !victim || victim==me) return 
		notify_fail("你想行窃的对象不在这里。\n");
	if( !victim->is_character())
		return notify_fail("你可用ｇｅｔ　＜东西＞　ｆｒｏｍ　＜容器＞。\n");
	if (victim->is_corpse())
		return notify_fail("不必偷了，直接拿就行。\n");
	if( !wizardp(me) && wizardp(victim) )
                return notify_fail("玩家不能偷天神身上的东西。\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, victim)) {
		if (stringp(victim->query("NO_KILL")))
			return notify_fail(victim->query("NO_KILL"));
		if (stringp(victim->query("NO_PK")))
			return notify_fail(victim->query("NO_PK"));	
		else 
			return notify_fail("你无法偷此人身上的东西。\n");
	}
		
        if( !ob = present(what, victim) ) {
                object *inv;
                inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail(victim->name() + "身上看起来没有什麽值钱的东西好偷。\n");
                ob = inv[random(sizeof(inv))];
        }
        
        sp = (me->query_skill("stealing") + me->query_kar())*100/360;
        	if( sp < 1 ) sp = 1;
        	if (sp > 100) sp=100;
        	if( me->is_fighting() ) {
                	sp /= 2;
                	me->start_busy(3);
        	}
        
        dp = (victim->query("sen")+ ob->weight()/10)*100/(me->query("sen")+1);
        	if (dp<100) dp = 100;
                if( victim->is_fighting() ) dp *= 3;
        	if( ob->query("equipped") ) dp *= 5;

        write("你不动声色地慢慢靠近" + victim->name() + "，等待机会下手\n……\n\n");
		if (wizardp(me)) tell_object(me,"sp="+(string)(sp)+", dp="+(string)(dp)+"\n");
        me->set_temp("stealing", 1);
        call_out( "compelete_steal", 3, me, victim, ob, sp, dp);
        return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp, int dp)
{
  
    	if (!me)	return;
    	
    	me->delete_temp("stealing");

//		if (me->query("class")!= "beggar") 
//			me->add("score",-1);
	
		if(!victim) {
        	tell_object(me, "太可惜了，你下手的目标已经不见了。\n");
            return;
        }
        
        if (!ob) {
        	tell_object(me, "太可惜了，你想偷的东西已经消失了。\n");
            return;
        }
        
        if (environment(ob)!= victim) {
        	tell_object(me,"怪了，这样东西已经不在此人身上了。\n");
        	return;
        }
        	
        
        if(environment(victim) != environment(me) ) {
            tell_object(me, "太可惜了，你下手的目标已经走了。\n");
            return;
        }
        
		if((int)ob->query("no_get")||(int)ob->query("lore")) {
			tell_object(me,"你似乎摸到了什么，不过没法掏出来。\n");
			return;
		}
        
        if( victim->query_temp("is_unconcious") || (random(sp+dp) > dp) ) {
                if( !ob->move(me) ) {
        	        tell_object(me, sprintf("你摸到一%s%s，可是对你而言太重了，不得不放弃。\n",ob->query("unit"),ob->name()));
                    return;
                }
                tell_object(me, HIW "得手了！\n\n" NOR);
                tell_object(me, sprintf("你成功地偷到一%s%s！\n",ob->query("unit"),ob->name()));
                if( living(victim) )
                if( random(sp) < dp/4 )
                        message("vision", sprintf("你看到%s鬼鬼祟祟地从%s身上偷走了一%s%s！\n",
                        			 me->name(),victim->name(),ob->query("unit"),ob->name()),
                        	environment(me), ({ me, victim }) );
                return;
        } else if( random(sp) > dp/4 ) {
                        tell_object(me, victim->name() + "不经意地一转头，你急忙将手缩了回去！\n还好，没有被发现。\n");
                        return;
        } 
        tell_object(me, HIR "糟糕！你失手了！\n\n" NOR);
        message_vision("$N一回头，正好发现$n的手正抓著$P身上的" + ob->name() + "！\n\n"+ "$N喝道：「干什麽！」\n\n", victim, me);

        if( userp(victim)) 
        	victim->fight_ob(me);
        else 
        	victim->kill_ob(me);
        
        me->fight_ob(victim);
                        
        me->perform_busy(5 - me->query_skill("stealing",1)/100);
	                         
//        me->add("thief", 1);
}



int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	steal <某物> from <某人>[0m
[0;1;37m────────────────────────────────[0m   

这个指令让你有机会偷到他人身上的东西。成功了, 当然你就能获得
该样物品。可是, 马有失蹄, 人总有失风的时候, 当你失败时当然就
得付出代价, 受害者对穷叫花子也许还会网开一面，对其他人可就不
会留情了。。。。


[0;1;37m────────────────────────────────[0m   

HELP
    );
    return 1;
}
 
