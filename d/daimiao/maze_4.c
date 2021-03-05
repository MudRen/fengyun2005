#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","镜中世界");
  set("long",@LONG
这是个镜子的世界。游目四望，不论是东南西北，抑或是天顶脚下，无处不覆
盖着明亮光洁的盈盈镜面。层层叠叠无数个的映像正在镜中满脸仓皇的与你对视，
看着环绕在周围的再熟悉不过的人影，一丝恐惧爬上了你的心头。
LONG
  );
  	set("exits",([
       	 "west":__DIR__"maze_3",
       	 "east":__DIR__"maze_5",
        ]));
	set("coor/x",40);
	set("coor/y",10);
	set("coor/z",0);
	set("no_fly",1);
		set("item_desc", ([
		"west":"四面皆是明镜，镜中影影绰绰的，尽数是你的影子。\n",
		"north":"四面皆是明镜，镜中影影绰绰的，尽数是你的影子。\n",
		"east":"四面皆是明镜，镜中影影绰绰的，尽数是你的影子。\n",
		"south":"四面皆是明镜，镜中影影绰绰的，尽数是你的影子。\n",
	]) );
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

