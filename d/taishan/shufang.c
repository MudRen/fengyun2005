// Room: shufang.c --- by MapMaker

inherit ROOM;

void create()
{
    set("short", "踏莎斋");

	set("long", @LONG
这里便是无垢山庄的书房了.但见房中一排排都是书架，架上都摆满了书，也
不知有多少书,正中是一张紫檀木的书桌，桌面金镶玉嵌，左首放着的砚台笔筒也
都雕刻精致.书桌右首是一只青铜古鼎，烧着檀香，鼎盖的兽头口中袅袅吐出一缕
缕青烟。
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
	"west":__DIR__"dating",
	]) );
        set("objects", ([
                __DIR__"npc/shenbijun" : 1,
        ]) );
        set("indoors", "taishan");
	set("coor/x",10);
	set("coor/y",70);
	set("coor/z",150);
	//}}

	setup();
	replace_program(ROOM);
}
