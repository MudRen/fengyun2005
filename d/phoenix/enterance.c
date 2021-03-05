// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit __DIR__"ann_room.c";

void create()
{
	object river,stone;
	set("short", "竹间清流");
        set("long", @LONG
走到竹林边缘，一条蜿蜒的小溪流斜横在你的眼前。溪水不深，底下铺着
一层浑圆可爱的卵石，垫着人蹑足而过。水花扑打在溪边的石子上，推挤着向
东面流去，声若玉珠溅碎，悦耳动听。举目望山，隐约可见一角红檐飞挂在青
郁林中，更高处是银妆积雪，在这东南之地甚是罕见。
LONG
        );
	set("objects", ([
		__DIR__"npc/mengye" : 1,
	]));
	set("exits",([
  		"up" : "/d/fy/fysquare",
  		"down" : "testroom",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
