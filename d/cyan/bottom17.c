// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{

	set("short", HIB"祭天塔外"NOR);
    set("long", @LONG
山谷深处是一座通体由乌木建筑的高塔屹立在满山的青碧之中，历经风吹
雨淋却依然完整，丝毫看不出岁月蚀刻的痕迹。塔门外放着两个活物一般的石
狮子，正炯炯有神地瞪着你；抬头仰望，只见匾额上龙飞凤舞的是四个金色阳
刻大字：
　　　　　　　　　　[45m[1;33m╔————————————╗[2;37;0m
　　　　　　　　　　[45m[1;33m∣　祭　　以　　天　　苍　∣[2;37;0m
　　　　　　　　　　[45m[1;33m╚————————————╝[2;37;0m　　　　　　　　

LONG
NOR
        );
	set("objects", ([

	__DIR__"npc/lion":2,
	__DIR__"npc/ye":1,

	]));
	set("no_fly",1);
	set("item_desc", ([

	"west":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"east":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"north":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"south":"山阴中处处有雾，你什么也分辨不清楚。\n",

	]) );
	set("exits",([
  		"south" : __DIR__"bottom16",
		"enter" : __DIR__"maze/entry",
	]) );

	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",-100);
	setup();
}

/*
int	valid_leave(object who, string dir)
{
	if (dir != "enter")
		return ::valid_leave(who,dir);

	if (!present("石狮子",this_object()))
		return ::valid_leave(who,dir);
	write("栩栩如生的石狮一双圆眼正瞪着你，气势迫得你停住脚步。\n");
	return notify_fail("");
}*/

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


