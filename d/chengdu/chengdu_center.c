// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "城中广场");
        set("long", @LONG
成都历史悠久，有“天府之国”、“蜀中江南”、“蜀中苏杭”的美称。成都
经济发达，文化繁荣，佛教盛行。此地建筑宏伟壮观，街道平坦宽阔，集市
之内百货云集、琳琅满目，官道之上人来人往、川流不息，繁荣异常。不过
也正是如此，一些江洋大盗、剪径毛贼也聚集于。
LONG
        );
	set("exits",([
  		"west" : __DIR__"xidajie1",
  		"east" : __DIR__"dongdajie1",
  		"north" : __DIR__"beidajie1",
  		"south" : __DIR__"nandajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}