// voted.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <ansi.h>
#define COL_PERIOD 300
inherit F_DBASE;

void check_vote(string what, string who);
string get_vip(object me);

void create() {
	seteuid( ROOT_UID );
}

int add_vote(object me, string what, string who) {
	string matter = who + "/" + what, ip;
	string* ip_list;
	
	// three things can happen when we adding a vote:
	// 1. Brand new vote, 2. Increment vote count, 3. decision vote
	
	// case 1, brand new votes
	if(!pointerp(ip_list = query(matter)) || sizeof(ip_list) < 1) {
		set(matter, ({ get_vip(me) }));
		call_out("check_vote", COL_PERIOD, what, who);
		return 1;
	}
	 
	// case 2 adding votes
	if(member_array((ip = get_vip(me)), ip_list) == -1) {
		add(matter, ({ ip }));
		return sizeof(ip_list) + 1;
	}
	return 0;
}

void matter_finalized(string what, string who) {
	delete(who + "/" + what);	
	if(sizeof(query(who)) < 1) {
		delete(who);
	}
}

void check_vote(string what, string who) {
	if(query(who + "/" + what)) {
		CHANNEL_D->do_sys_channel(
				"vote","由于票数不够，关于对"+who+"实行"+what+"的表决现在取消。");
		matter_finalized(what, who);
	}
}

string get_vip(object me) {
	string ips;
	string pa,pb,pc,pd;
	
	if(stringp(ips = query_ip_number(me)) && sscanf(ips,"%s.%s.%s.%s",pa,pb,pc,pd) == 4) {
		return pa + "." + pb + "." + pc + ".*";
	} else {
		return "0.0.0.0";
	}
}
