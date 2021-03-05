// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "南大街");
        set("long", @LONG
南大街
LONG
        );
	set("exits",([
  		"west" : __DIR__"chengdukezhan",
  		"east" : __DIR__"tianshangrenjian",
  		"north" : __DIR__"chengdu_center",
  		"south" : __DIR__"nandajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}