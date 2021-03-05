// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "东门");
        set("long", @LONG
东门
LONG
        );
	set("exits",([
  		"west" : __DIR__"dongdajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}