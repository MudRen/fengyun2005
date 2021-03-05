// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "离音谷");
    set("long", @LONG
离音谷地中满布着荧荧白石，有一道蜿蜒溪流自南向流过，小谷中溪水横
洞，波声潺潺，间或有几声鹤唳，倒也别具一方幽情。谷中似已经多年渺无人
迹，有一些前来喝水的小动物一点儿也不怕生，正睁着圆圆的大眼睛好奇地打
量着你。
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/cat":1,
	__DIR__"npc/turtle":1,
		__DIR__"obj/river" : 1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : "path8",
  		"southup" : "peak11",
  		"northup" : "peak10",
  		"eastdown" : "patha",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",70);
	setup();
}

void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("溪水", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/stone");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/stone");
		if(stone)
			stone->move(river);
	}
	return;
}



int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (dir != "southup")
		if (REWARD_D->riddle_check(me,"天涯魂梦") == 1) 
			return notify_fail("还是先去找师傅吧。\n");

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


