// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "操场");
        set("long", @LONG
大门往南有教军场一座，为将士练兵的地方。有检阅台，称“演武台”。 
LONG
        );
	set("exits",([
  		"west" : __DIR__"yingfang1",
  		"east" : __DIR__"yingfang2",
  		"north" : __DIR__"chaotinghuoqiyingdamen",
  		"south" : __DIR__"caochang2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}