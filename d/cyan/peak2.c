// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "凌云顶");
    set("long", @LONG
甫登上凌云绝顶，你便因眼前景色一楞。四面怪石嶙峋、林木葱葱、崖壁
陡峭，只是这渺无人迹的绝顶之上，竟有一座崭新的大屋，屋外一串鲜红的灯
笼在峰顶凛冽的风中飞荡，其上“四海客栈”几个大字清晰可辨，屋中通明的
灯火昭示着万物之灵的存在，彻底颠覆了你对凌云绝地的认知。
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/rock2":1,
	__DIR__"obj/woods":1,
	__DIR__"obj/lantern":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"enter" : __DIR__"hotel",
  		"southdown" : __DIR__"peak1",
	]) );

	set("outdoors", "cyan");

	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",80);
	setup();
}

void init(){
	add_action("do_look", "look");
}

int do_look(string arg) {
if (!arg)
	return 0;
	if (arg == "灯笼")
	{
		write("一串鲜红鲜红且散着光芒的灯笼，在大风里来回飞荡。"NOR"\n");
		return 1;
	}
	return 0;
}

void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("灯笼", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/kindling");
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


