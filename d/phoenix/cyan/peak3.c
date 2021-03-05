// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "瞭望台内");
    set("long", @LONG
这一处戒备森严，空气中竟隐隐弥漫著烽火金戈之气。四面的青砖石瓦亮
洁如新，整排整排锃亮的梨花铁枪并立在左墙兵器架上，右墙上则开了数个垛
口，战时在垛口上既可以长弓钳制整个明霞山道，亦可指挥瞭望台上的天罡破
阵弩以风引之箭远射，将风云城东直至帝王谷的数十里道路尽数涵覆。
LONG
NOR
        );
	set("objects", ([
//	__DIR__"obj/pot":2,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : "path6",
	]) );

	set("area","cyan");

	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",90);
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


