// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "剑阁");
        set("long", @LONG
剑阁
LONG
        );
	set("exits",([
  		"down" : __DIR__"jiange1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}