// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", YEL"黄树林"NOR);
    set("long", @LONG
挤出狭窄的山缝，迎接你的是一片奇特的树林。从未见过的各种参天巨木
如列阵般在黑软的淤泥上排布得井然有序，远远看去，犹如墨盘上还未动过的
木棋。仰头上望，但见覆满苍穹的木叶竟无一片苍碧，满满漾着浅浅的鹅黄，
枝条如镀金边，构筑为一种奇异诡谲的美丽。
    不知名的季节，微风。
    金色的光线从树顶中浅浅地透了下来。
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : __DIR__"path4",
  		"southdown" : __DIR__"forest2",
  		"eastup" : __DIR__"path5",
	]) );

	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",50);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	if (!random(7))
		tell_object(me,YEL"你隐隐闻到了一种淡淡的金色的香气。\n"NOR);
	return ::valid_leave(who,dir);
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


