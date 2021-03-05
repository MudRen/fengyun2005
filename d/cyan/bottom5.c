// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", CYN"幽幻谷"NOR);
    set("long", @LONG
此处阴云相夹，东西难辨，黑雾迷空，前进的道路上拦着一块庞大无匹
的青石，青石上铭着赤红的文字，周遭的景色在憧憧的雾气中若隐若现，冷
冷的风掠过，你想起幼年时听街坊提过的地狱景色，直要怀疑自己已然不在
人间。
LONG
NOR
        );
	set("objects", ([

	__DIR__"obj/rock4.c":1,

	]));
	set("no_fly",1);
	set("no_light",1);
	set("item_desc", ([

	"west":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"east":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"north":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"south":"山阴中处处有雾，你什么也分辨不清楚。\n",

	]) );
	set("exits",([
  		"south" : __DIR__"bottom4",
  		"east" : __DIR__"bottom6",
  		"west" : __DIR__"bottom8",
	]) );

	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",-100);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	tell_object(me,CYN"你浑身戒备，小心翼翼地向雾气中走去．．．\n"NOR);
	me->perform_busy(1);
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


