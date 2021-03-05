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
  		"west" : __DIR__"chengduyaodian",
  		"east" : __DIR__"nangongqianzhuang",
  		"north" : __DIR__"nandajie1",
  		"south" : __DIR__"nanmen",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}