// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "赌场");
        set("long", @LONG
黄麻子的儿子，黄小麻子在成都开的小赌场。大厅里真是金碧辉煌，
堂皇富丽，连烛台都是纯银的，在这种地方输了千儿八百两金子，没人
会觉得冤枉。大厅里摆满了大大小小的赌桌，只要能说出名堂的赌具，
这里都有。有匾（ｓｉｇｎ）一块。
LONG
        );
	set("exits",([
  		"east" : __DIR__"beidajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}