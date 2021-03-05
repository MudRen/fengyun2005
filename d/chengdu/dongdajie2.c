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
  		"west" : __DIR__"dongdajie1",
  		"east" : __DIR__"dongmen",
  		"northeast" : __DIR__"tulu",
  		"southeast" : __DIR__"chaotinghuoqiyingdamen",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}