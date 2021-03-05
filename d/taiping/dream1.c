#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "雾一样的地方");
        set("long", @LONG
只觉眼前一亮，又看到了光。迷朦的光芒，来自你的上方，很柔和，象隔着一
张纱帘。有风。风吹起了你衣袂。阴森森的冷风，吹在身上却没有寒冷的感觉。有
雾。凄迷的白雾，飘浮在你的周围，却没有阻碍你的视线。
LONG
        );
        set("exits", ([ 
		"up":  __DIR__"dream2",
	]));
        set("no_fly",1);
        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


