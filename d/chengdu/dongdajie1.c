// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "东大街");
        set("long", @LONG
东大街
LONG
        );
	set("exits",([
  		"west" : __DIR__"chengdu_center",
  		"east" : __DIR__"dongdajie2",
  		"south" : __DIR__"chengdudangpu",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}