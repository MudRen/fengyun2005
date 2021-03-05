
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "低矮石屋");
        set("long", @LONG
这是一间低矮的屋子，四壁都是厚实的黑石，屋中带着些许轻微的潮气，石壁
贴近地面的地方爬着一层薄薄的乌苔。石屋的四面各立着一扇石门，或开或闭。出
路也许就在石门之后，可是究竟哪一扇门才是生机？
LONG
        );
	set("room_num",18);
	set("exits",([
//  		"west" : __DIR__"couplemaze_"+(query("room_num")-1),
//  		"east" : __DIR__"couplemaze_"+(query("room_num")+1),
//  		"north" : __DIR__"couplemaze_"+(query("room_num")-6),
//  		"south" : __DIR__"couplemaze_"+(query("room_num")+6),
	]) );
	set("exist_exits",query("exits"));
	// nothing
	set("no_fly",1);
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
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

