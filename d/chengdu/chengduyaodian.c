// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "成都药店");
        set("long", @LONG
普生和快活王在成都联手经营的药店。药店成立后，大大方便了病人，
和下毒之人。整个药店弥漫着草药味，四下搁的也都是些知名不知名的草
药，和毒药。
LONG
        );
	set("exits",([
  		"east" : __DIR__"nandajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}