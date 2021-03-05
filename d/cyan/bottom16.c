// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "悬天古径");
    set("long", @LONG
离开血腥气息浓厚的谷地，你终能稍稍喘息。面前是一条摇摇晃晃的索道
，拉直在悬崖中心，向悬崖对面看去，只见一座乌木的高塔屹立在青碧之中，
格外引人注意。只是索道年久失修，下面又是万仞深谷，若落下去必定是尸骨
无存，让人提步前难免要再三犹豫。
LONG
NOR
        );
	set("objects", ([

	]));
	set("no_fly",1);
	set("item_desc", ([

	"west":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"east":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"north":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"south":"山阴中处处有雾，你什么也分辨不清楚。\n",

	]) );
	set("exits",([
  		"north" : __DIR__"bottom17",
  		"west" : __DIR__"bottom11",
	]) );

	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",-100);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (!random(3))
	{
		tell_object(me,HIG"你脚下一滑，在索道上打了个趔趄，险些摔了出去！\n"NOR);
		me->perform_busy(2);
		return notify_fail(" ");
	}
	else
		tell_object(me,"你一步一脚印，慢慢地沿着索道前行．．．\n"NOR);
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


