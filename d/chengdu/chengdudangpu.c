// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "成都当铺");
        set("long", @LONG
此间当铺很小，但却有一间很大的储藏室。当铺的四周堆满了东西，就
连墙上也挂满了只要是能挂起来的东西，每件东西上都有一张当票。所有堆
积的东西都布满了灰尘，显然是很多人将东西典当于此，却再也没有回来取。
LONG
        );
	set("exits",([
  		"north" : __DIR__"dongdajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}