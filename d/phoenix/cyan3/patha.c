// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "潮径");
    set("long", @LONG
自映景明湖中流下的水，渗透了离音谷的堆堆白石，蜿蜒着向这个方向流
下，细窄水道的两边，青碧的野草长得分外茂密，也滤得空气沁人心脾。尽管
这条小径宽不盈丈，在这里漫步也格外让人舒心。
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/grass":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : "peak7",
  		"eastdown" : "pathb",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-10);
	set("coor/y",50);
	set("coor/z",60);
	setup();
}

void reset()
{
	object river,stone,*inv;
	
	::reset();



	river = present("野草", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1 && !random(2))
	{
		stone = new(__DIR__"obj/brokenflute");
		if(stone)
			stone->move(river);
	}


	return;
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


