// vote.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <ansi.h>
#include <vote.h>
inherit F_CLEAN_UP;

int main(object me, string arg) {
	string who,what;
	string msg;
	object victim;
	int result;
	int diff;
	
	seteuid(getuid());
	if((int)me->query("mud_age") < NEW_PERIOD) {
		return notify_fail("你还没有到能投票的年纪！\n");
	}	
	if((int)me->query("level") < NEW_LEVEL) {
		return notify_fail("国内站规定玩家等级必须达到"+NEW_LEVEL+"！\n");
	}
	if(!arg) {
		return notify_fail("指令格式：vote <what> on <who>\n");
	}
	if(sscanf(arg,"%s on %s",what,who)	!= 2) {
		return notify_fail("指令格式：vote <what> on <who>\n");
	}
	if(!objectp(victim = find_player(who)) || !userp(victim)) {
		return notify_fail("咦．．．有这个人吗？\n");
	}
	if(me==victim) {
		return notify_fail("你不可以投自己的票！\n");
	}
	if(wizardp(victim)) {
		return notify_fail("你不可以剥夺他/她的任何权力！\n");
	}
	log_file("VOTE",sprintf("%s:%s(%s)[%s] vote %s on %s(%s)\n",
			ctime(time()),me->name(1),me->query("id"),
			query_ip_number(me),
			what,victim->name(1),victim->query("id")));	
	switch(what) {
		case "kickout":
			result = VOTE_D->add_vote(me,what,who);
			if(!result) {
				return notify_fail("已经有人从你连线的域名投过票了！\n");
			}
			if((diff = KICKOUT_NO - result) > 0) {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)投票剥夺%s(%s)进入风云的权利，还差%s票。",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id"),
						chinese_number(diff)));
			} else {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)投票剥夺%s(%s)进入风云的权利，表决通过。",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id")));
				victim->set("kickout_time",time());
				victim->save();
				victim->ccommand("quit");
				seteuid(ROOT_UID);
				if (victim)	destruct(victim);
				VOTE_D->matter_finalized(what,who);
			}
			break;
		case "chblk":
			if(victim->query("chblk_on")) {
				return notify_fail("他/她已经被剥夺了使用公共频道的权力！\n");
			}
			result = VOTE_D->add_vote(me,what,who);
			if(!result) {
				return notify_fail("已经有人从你连线的域名投过票了！\n");
			}
			if((diff = CHBLK_NO - result) > 0) {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)投票剥夺%s(%s)使用公共频道的权利，还差%s票。",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id"),
						chinese_number(diff)));
			} else {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)投票剥夺%s(%s)使用公共频道的权利，表决通过。",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id")));
				victim->set("chblk_on",1);
				victim->save();
				VOTE_D->matter_finalized(what,who);
			}
			break;
		case "chnoblk":
			if(!victim->query("chblk_on")) {
				return notify_fail("他/她没有被剥夺了使用公共频道的权力！\n");
			}
			result = VOTE_D->add_vote(me,what,who);
			if(!result) {
				return notify_fail("已经有人从你连线的域名投过票了！\n");
			}
			if((diff = CHNOBLK_NO - result) > 0) {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)投票给予%s(%s)使用公共频道的权利，还差%s票。",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id"),
						chinese_number(diff)));
			} else {
				CHANNEL_D->do_sys_channel("vote",sprintf(
						"%s(%s)投票给予%s(%s)使用公共频道的权利，表决通过。",
						me->name(1),
						me->query("id"),
						victim->name(1),
						victim->query("id")));
				victim->delete("chblk_on");
				victim->save();
				VOTE_D->matter_finalized(what,who);
			}
			break;
		default:
			return notify_fail("指令格式：vote <what> on <who>\n");
			break;
	}
	return 1;
}

int help(object me) {
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	vote <what> on <who>[0m
[0;1;37m────────────────────────────────[0m   

这条指令是众玩家在没有管理人员在线的时候来处理
违反风云天条的人的，需要在五分钟内有足够票数才可以生效。

其中<what>可以是以下中的一项：

kickout:	剥夺进入风云的权利（需要十五票）
chblk:		剥夺使用公共频道的权力（需要七票）
chnoblk:	给予使用公共频道的权力（需要五票）

注：所有的投票活动都有记录，凡是滥用投票的人一经察出都会
按照风云天条处置！

[0;1;37m────────────────────────────────[0m
HELP);
	return 1;
}
