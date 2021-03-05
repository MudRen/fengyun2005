// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "北大街");
        set("long", @LONG
北大街
LONG
        );
	set("exits",([
  		"east" : __DIR__"dupucaotang",
  		"west" : __DIR__"tudimiao",
  		"north" : __DIR__"beimen",
  		"south" : __DIR__"beidajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}