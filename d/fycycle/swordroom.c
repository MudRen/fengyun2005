#include <room.h>
inherit ROOM;
void create()
{
	set("short", "江海清光");
	set("long", @LONG
眼前晶光耀目，如同江海浮动的清波。你定睛细看，发现全屋竟然都是明玉
雕成。周室上下，完全不按建筑格式，却似乎依照水波的趋势形成一种奇妙的阵
法。屋中心，波光汇聚，似乎结成一柄流光闪闪的宝剑。
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/swordbook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    	setup();
}


/*
void reset()
{
	object *inv;
	object endtable, item, item1;
	string book;
	string *books = ({"hanmeiforce", "dodgebook", "axsteps", "qiuzhisword"});
	::reset();
	book = books[random(4)];
	endtable = present("endtable", this_object());
	inv = all_inventory(endtable);
	if( !sizeof(inv)) 
	{
		item = new(__DIR__"obj/forcebook");
		item->move(endtable);
		item = new(__DIR__"obj/movebook");
		item->move(endtable);
		item = new(__DIR__"obj/swordbook");
		item->move(endtable);
		item1 = new(__DIR__"obj/" + book);
		item1->move(endtable);
	}
	::reset();
}

*/