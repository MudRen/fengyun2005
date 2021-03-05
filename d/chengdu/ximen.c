// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "西门");
        set("long", @LONG
西门
LONG
        );
	set("exits",([
  		"east" : __DIR__"xidajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}