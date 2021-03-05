#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
	set("short", "如意客栈");

	set("long", @LONG
客栈在一楼的睡房，房间里看起来干干净净，唯一的摆设就是一张很大
很大的床，看上去前不久还有被使用过的痕迹。房内有个油头粉面的男人，
看上去很腻人。
LONG);

	set("type","house");
	set("exits",([
		"east":__DIR__"kezhan",
	]) );
	
	set("coor/x",-10);
	set("coor/y",110);
	set("coor/z",0);
	setup();
	set("no_fly", 1);
	set("max_lv",40);
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"kezhan");
	if (!exitroom)
		exitroom = load_object(__DIR__"kezhan");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"客栈老板陪笑道：那间房已经有位客官订下了。\n"NOR);
	}
}

