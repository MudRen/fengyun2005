// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "成都客栈");
        set("long", @LONG
成都客栈的规模较大。并设有酒窖、食品室及厨房，满足客人更多的需求。
屋檐下悬挂着长方形白纸灯笼，灯笼两面都写有联语“未晚先投宿，鸡鸣早看天”。
入夜，灯火闪亮。旅客远远看见，便知来到了打点住宿之处，那一刻，所有身心
的疲惫就顿然消减了。
LONG
        );
	set("exits",([
  		"east" : __DIR__"nandajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}