// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "飞来石");
        set("long", @LONG
攀上了相思雪峰的最高处，一片不甚宽广的雪地出现在你的眼前。银白色
的冰雪压覆在山顶，低头望去，山中飘游的云雾已尽皆在你脚下。雪地的边上
有一块巨大的卵形灰岩，斜卧在雪上浅浅的凹槽之中，岩上刻着＂飞来之石＂
四字。每当微风吹过，灰岩就在槽中轻轻摇晃。
LONG
        );
	set("objects", ([
		__DIR__"npc/mengye" : 1,
		__DIR__"obj/rock5" : 1,
	]));
	set("exits",([
  		"southdown" : __DIR__"huxian",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",40);
	setup();
}



void reset(){
	::reset();
	if (!random(48))	// 平均12小时还原。
	{
		delete("no_stone");
        set("long", @LONG
攀上了相思雪峰的最高处，一片不甚宽广的雪地出现在你的眼前。银白色
的冰雪压覆在山顶，低头望去，山中飘游的云雾已尽皆在你脚下。雪地的边上
有一块巨大的卵形灰岩，斜卧在雪上浅浅的凹槽之中，岩上刻着＂飞来之石＂
四字。每当微风吹过，灰岩就在槽中轻轻摇晃。
LONG
        );
	}
	if (query("no_stone"))
	{
		if (present("飞来石"))
		{
			destruct(present("飞来石"));
		}
	}
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
