// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "南门");
        set("long", @LONG
南门
LONG
        );
	set("exits",([
  		"north" : __DIR__"nandajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}