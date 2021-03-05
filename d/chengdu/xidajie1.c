// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "西大街");
        set("long", @LONG
西大街
LONG
        );
	set("exits",([
  		"west" : __DIR__"ximen",
  		"east" : __DIR__"chengdu_center",
  		"north" : __DIR__"wuhouci1",
  		"south" : __DIR__"fuweibiaoju1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}