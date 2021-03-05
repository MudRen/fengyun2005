#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "断崖边");
        set("long", @LONG
行不多时，人踩过的痕迹就消失不见，再往前走一小段，就见山道已经到了尽
头，眼见前面是个断崖，已然无路可走。从崖上下望，但见山谷中云气缭绕，白雾
迷蒙，崖壁上草木不生。
LONG
        );
	set("exits",([
  		"southup" : __DIR__"hole1",
	]) );
	set("no_fly",1);
	set("item_desc", ([
		"断崖": "断崖十分陡峭，崖壁上草木不生，间或有几块石头突出。\n",
		"崖": "断崖十分陡峭，崖壁上草木不生，间或有几块石头突出。\n",
		"cliff": "断崖十分陡峭，崖壁上草木不生，间或有几块石头突出。\n",
	]) );
	set("coor/x",-40);
	set("coor/y",200);
	set("coor/z",180);
	set("outdoors", "bashan");
	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me = this_player(),env=this_object();
	if (!arg)
		return notify_fail("你要爬什么？\n");
	if (arg != "cliff" && arg != "down" && arg != "崖" && arg != "断崖")
		return notify_fail("你要爬什么？\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你现在正忙。\n");
	
	message_vision(CYN"$N向山崖下爬去．．．\n"NOR,me);
	call_out("do_climbdown",2,me,env);
	me->perform_busy(3);
	return 1;
}

int do_climbdown(object me,object env)
{
	object room;
	room = find_object(__DIR__"hole3");
	if (!room)
		room = load_object(__DIR__"hole3");
	if (!me || environment(me) != env)
		return 0;
	tell_object(me,CYN"你抓着突起的石块，小心翼翼的爬下．．．\n"NOR,me);
	me->move(room);
	message_vision(CYN"$N慢慢的从山崖上爬了下来。\n"NOR,me);
	return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
