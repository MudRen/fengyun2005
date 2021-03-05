#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "地穴");
        set("long", @LONG
眼前，是一片黑暗，什么也看不到。没有寒冰，没有烈焰，也没有雾，甚至连
风都已静止。反手摸去，着手竟是泥土的感觉，鼻子同时亦嗅到了潮湿的泥土气味。
这里并不是奇浓嘉嘉普。这里是什么地方？
LONG
        );
        set("exits", ([ 
		"east":  __DIR__"basement2",
	]));
	set("objects", ([
               	
    	]) );
        set("no_fly",1);
        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

