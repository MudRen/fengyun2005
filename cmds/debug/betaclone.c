// clone.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/14/2001 by Daniel Q. Yu.
//

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file) {
	object obj;
	string err, msg;
	
	seteuid(geteuid(me));
	
	if(!file) {
		file = me->query("cwf");
	}
	if(!file) {
		return notify_fail("你要复制什麽物件？\n");
	}
	
	file = resolve_path(me->query("cwd"), file);
	if(sscanf(file, "%*s.c") != 1) {
		file += ".c";
	}
	me->set("cwf", file);
	if(file_size(file) < 0) {
		return notify_fail("没有这个档案(" + file + ")。\n");
	}
	if(!find_object(file)) {
		err = catch(call_other(file, "???"));
		if(err){
			write("载入失败：" + err + "\n");
			return 1;
		}
	}
	err = catch(obj = new(file));
	if(err){
		write("复制失败：" + err + "\n");
		return 1;
	}
	if(!objectp(obj)) {
		write("复制失败。\n");
		return 1;
	}
	log_file("CLONE_LOG", sprintf("(%s)\n%s cloned %s\n", ctime(time()), 
			me->query("name"), file));
	if(!stringp(msg = me->query("env/msg_clone"))) {
		msg = "$N在怀中摸索一番，拿出了$n。\n";
	}
	if(!obj->is_character() && obj->move(me)) {
		write(obj->query("name") + "复制成功，放在你的物品栏。\n");
		message_vision(msg + "\n", me, obj);
		return 1;
	}
	if(obj->move(environment(me))) {
		write(obj->query("name") + "复制成功，放在这个房间。\n");
		message_vision(msg + "\n", me, obj);
		return 1;
	}
	destruct(obj);
	return notify_fail("无法复制不能移动的物件(" + file + ")。\n");
}

int help(object me) {
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	clone <档名> [0m
[0;1;37m────────────────────────────────[0m     

利用此指令可复制任何能移动之物件(含怪物)。
所有复制物品都有LOG纪录。

[0;1;37m────────────────────────────────[0m     
HELP
    );
    return 1;
}
