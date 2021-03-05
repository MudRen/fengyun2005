// team.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
		object *t,*t1, *players;
		int i, me_exp, ob_exp, num, num1, n, max_exp;
	


//		First remove those 1-man bogus team, mostly due to unclean code.
		if (sizeof(me->query_team())<2) 	me->dismiss_team();

//		队伍列表
	
		if( !arg ) {
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"你现在并没有参加任何队伍。\n"NOR);
			write(WHT"你的“"+ me->query_temp("team_name") + "”中的成员有：\n  "NOR + implode(t->name(1), "\n  ") + "。\n"NOR);
			return 1;
		}

//		解散队伍或脱离队伍
		if( arg=="dismiss" ) {
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"你现在并没有参加任何队伍。\n"NOR);
			if( me->is_team_leader() ) {
				message("team", WHT""+me->name(1) + "将队伍解散了。\n"NOR, t, me);
				write(WHT"你将队伍解散了。\n"NOR);
			} else {
				message("team", WHT""+me->name(1) + "决定脱离队伍。\n"NOR, t, me);
				write(WHT"你脱离了你的队伍。\n"NOR);
			}
			me->dismiss_team();
			return 1;
		}

//		队伍命名。
		if (sscanf (arg, "name %s", arg) == 1) {
			if (!me->is_team_leader())
				return notify_fail(WHT"只有领队人才能够命名队伍名称。\n");
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"你现在并没有参加任何队伍。\n"NOR);
			if (sizeof(arg)>14)
				return notify_fail(WHT"旗号最多为六个字。\n"NOR);
			
			if (userp(me) && me->query_temp("timer/team_name") + 4 > time())
				return notify_fail(WHT"你的旗号变得太频繁了，等一分钟吧。\n"NOR);
			players = filter_array(livings(), (: userp($1):));
			num = sizeof(players);
			while (num--)
				if (players[num]->query_temp("team_name") == arg)
					return notify_fail("这个旗号已经有人在使用了。\n");
			me->set_temp("timer/team_name",time());
			for(i=0; i<sizeof(t); i++) {
				t[i]->set_temp("team_name",arg);
				tell_object(t[i],YEL"你的队伍旗号改为“"+arg+YEL"”。\n"NOR);
			}			
			return 1;
		
		}			
		


//		开除队伍中某一人	
		if(sscanf(arg, "dismiss %s", arg) == 1) {
			object ob;
			ob = find_player(arg);
			if(!ob || !me->visible(ob)){
				return notify_fail(WHT"没有这个人....。\n"NOR);
			}
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"你现在并没有参加任何队伍。\n"NOR);
			if( !me->is_team_leader() ) {
				return notify_fail(WHT"你不是领队人。\n"NOR);
			} else if ( me->is_team_leader() && me==ob) {
				return notify_fail(WHT"解散队伍直接使用team dismiss，否则请先指定下任领队（team promote）\n"NOR); 
			} else { 
				for(i=0; i<sizeof(t); i++) {
					if(t[i]->name() == ob->name()){
						if (me==ob) {
							message("team", WHT""+me->name(1) + "将队伍解散了。\n"NOR, t, me);
							write(WHT"你将队伍解散了。\n"NOR);
						} else {
							message("team", WHT""+me->name(1) + "决定把" + ob->name()+ "踢出队伍。\n"NOR, t, me);
							write(WHT"你决定把" + ob->name() + "踢出队伍。\n"NOR);
							tell_object(ob,WHT"你被你的队伍开除。\n"NOR);
						}
						ob->dismiss_team();
						return 1;
					}
				} 
				return notify_fail(WHT""+ob->name() + "不在你的队伍中。\n"NOR);
			}
			return 1;
		}

//		转让首领

		if (sscanf(arg,"promote %s", arg) == 1) {
			object ob, bb;
			ob = find_player(arg);
			if(!ob || !me->visible(ob)){
				return notify_fail(WHT"没有这个人....。\n"NOR);
			}
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"你现在并没有参加任何队伍。\n"NOR);
			if( !me->is_team_leader() ) {
				return notify_fail(WHT"你不是领队人，无法转让领队。\n"NOR);
			}  else if ( me == ob) {
				return notify_fail(WHT"你已经是领队人了。\n"NOR);
			} else if (me->team_member(ob)){ 
				me->switch_team_member(me,ob);
				me->tell_team(me,WHT""+ me->name(1) + "将领队权交给了" + ob->name(1)+"。\n"NOR);	
				return 1;
			}	
			return notify_fail(WHT""+ob->name() + "不在你的队伍中。\n"NOR);
		}

//		邀请入队。

		if( sscanf(arg, "with %s", arg)==1 ) {
			object ob;
			if( !(ob = present(arg, environment(me)))
				||	!living(ob)
				||	!ob->is_character()
				||	ob==me )
					return notify_fail(WHT"你想和谁成为夥伴？\n"NOR);
		
			if (sizeof(ob->query_team())<2) 	ob->dismiss_team();
			
		//	(1) 检查是否合法 	
			if( ob->query("quest"))
				return notify_fail(WHT"对方还有没完成的任务，不能组队！\n"NOR);
			
			ob_exp = ob->query("combat_exp");
			me_exp = me->query("combat_exp");
			n = 3;
			
			if (pointerp(t=me->query_team())) {
			// If Me is in a team
				if (!me->is_team_leader())
					return notify_fail(WHT"只有队伍领袖可以邀请别人加入。\n"NOR);
				else if (sizeof(me->query_team())>5)
					return notify_fail(WHT"队伍最多是六个人。\n"NOR);
				else {
					num= sizeof(t);
					max_exp = 0;
					while(num--) {
						if (t[num]->query("combat_exp")> max_exp)
							max_exp = t[num]->query("combat_exp");
					}
					num= sizeof(t);
					while (num--) {
						if (t[num]->query("quest") && max_exp < ob_exp)
							return notify_fail(WHT"队伍中的任务低于加入者经验，需要先完成任务。\n"NOR);
						if (n*t[num]->query("combat_exp")<ob_exp 
							|| t[num]->query("combat_exp")+ 2000000< ob_exp)
							return notify_fail(WHT"组队经验范围差别太大。\n"NOR);
						if (t[num]->query("combat_exp")>n*ob_exp 
							|| t[num]->query("combat_exp")> ob_exp+ 2000000)
							return notify_fail(WHT"组队经验范围差别太大。\n"NOR);	
						
					}
				}
			} else {	// Or I am not in a team	
				if( me->query("quest"))
					return notify_fail(WHT"你还有没完成的任务，不能组队！\n"NOR);
				if (n * me_exp<ob_exp || me_exp + 2000000< ob_exp)
					return notify_fail(WHT"组队经验范围差别太大。\n"NOR);
				if (me_exp>n * ob_exp || me_exp > ob_exp + 2000000)
					return notify_fail(WHT"组队经验范围差别太大。\n"NOR);	
			}
	
		//	A邀请B，以上证实A及其队伍，以及B本身是合法的，但是不检查B的队伍。
				
		//	当B再次输入team with 时，A/B以及B的队伍会再次通过上述检查，
		//	但是A的队伍，以及B是否加入其他队伍中可能已有变动，须在下面复查。	
		
			if( !pointerp(me->query_team()) || me->is_team_leader() ) {
				if( me==(object)ob->query_temp("pending/team") ) {
					//	检查A队伍是否合法。非队伍的情况已经在上面检查过了。
					if (pointerp(t1=ob->query_team())) {
						// If Ob is in a team
						if (me->query_team())
							return notify_fail(WHT"你已经在某个队伍中了。\n"NOR);				
						if (!ob->is_team_leader())
							return notify_fail(WHT"只有队伍领袖可以邀请别人加入。\n"NOR);
						else {
							num= sizeof(t1);
							max_exp = 0;
							while(num--) {
								if (t1[num]->query("combat_exp")> max_exp)
									max_exp = t1[num]->query("combat_exp");
							}
							num= sizeof(t1);
							while (num--) {
								if (t1[num]->query("quest") && max_exp < me->query("combat_exp"))
									return notify_fail(WHT"对方队伍中的任务低于你的经验值，暂时不能加入。\n"NOR);
							if (n*t1[num]->query("combat_exp")<me_exp 
								|| t1[num]->query("combat_exp")+ 2000000< me_exp)
								return notify_fail(WHT"组队经验范围差别太大。\n"NOR);
							if (t1[num]->query("combat_exp")>n*me_exp 
								|| t1[num]->query("combat_exp")> me_exp+ 2000000)
								return notify_fail(WHT"组队经验范围差别太大。\n"NOR);	
							}
						}
					} 								
					if( !pointerp(me->query_team()) ) {
						ob->add_team_member(me);
						message_vision(WHT"$N决定加入$n的“"+me->query_temp("team_name")+"”。\n"NOR, me, ob);
					} else {
						me->add_team_member(ob);
						message_vision(WHT"$N决定让$n加入队伍。\n"NOR, me, ob);
						tell_object(ob,YEL"你的队伍旗号是"+ me->query_temp("team_name")+"。\n");
					}
					ob->delete_temp("pending/team");
					return 1;
				} else {
					if(pointerp(ob->query_team())) {	//检查B是否已有队伍。
						if (sizeof(me->query_team())<2)
							return notify_fail(ob->name()+"已经属于别的队伍了，你另外再找人吧。\n");
						if (member_array(ob, me->query_team())== -1)
							return notify_fail(ob->name()+"已经属于别的队伍了，你另外再找人吧。\n");
						else
							return notify_fail(ob->name()+"已经在你的队伍中了。\n");
					}
					message_vision(WHT"$N邀请$n加入$P的队伍。\n"NOR, me, ob);
					tell_object(ob, YEL "如果你愿意加入，请用 team with " + me->query("id") + "。\n" NOR);
					me->set_temp("pending/team", ob);
					return 1;
				}
			} else
				return notify_fail(WHT"只有队伍领袖可以邀请别人加入。\n"NOR);
		}
        
	
		if( sscanf(arg, "talk %s", arg)==1 )   {
			t= me->query_team();
	        if( !pointerp(t) )
	           	return notify_fail("你现在并没有和别人组成队伍。\n");
			for(i=0; i<sizeof(t) ; i++)
				if (!objectp(t[i])) return notify_fail("你需要重新组合队伍。\n");
			t -= ({ 0 });
			if (sizeof(t)==1)
				return notify_fail("你的队伍里只有你自己了。\n");	
	        return CHANNEL_D->do_channel(me, "teamtalk", arg);
		}

	/*
	if( sscanf(arg, "form %s", arg)==1 ) {
		if( !pointerp(t=me->query_team()) || !me->is_team_leader() )
			return notify_fail("你必须是一个队伍的领袖才能组织阵形。\n");
		if( !me->query_skill(arg, 1) )
			return notify_fail("这种阵形你没学过。\n");
		return SKILL_D(arg)->form_array(me);
	}*/
}





int help(object me)
{
	write(@HELP

[0;1;37m────────────────────────────────[0m
队伍指令使用方法:

team with <某人> - 跟某人组成队伍. 必须要双方都同意加入才会生效。
team name <某名> - 队伍领队可更改此队伍的旗号。
team dismiss     - 离开队伍. 若下此指令的是领队, 则整个队伍会解散。
team dismiss <某人> - 对伍的领队可以随时开除队伍中的某人。
team promote <某人> - 队伍的领队可以把领队转让给队伍中的某人
team talk <讯息> - 跟队伍里其他的人谈话, 可以用 tt <讯息> 替代。

直接下 team 指令时则会显示你目前是否有加入队伍及队员名单。

注: team 跟 follow 是独立的，你不一定要 follow 队伍的领袖。

注：组队时经验值不能相差太大，新加入者不能有任务在身，
	如果队伍中最高经验值大于新加入者，则队伍中也不能有任务。
	
[0;1;37m────────────────────────────────[0m  

HELP
	);
	return 1;
}
