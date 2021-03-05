// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "北门");
        set("long", @LONG
北门
LONG
        );
	set("exits",([
  		"south" : __DIR__"beidajie2",
  		"northeast" : __DIR__"shudao1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}