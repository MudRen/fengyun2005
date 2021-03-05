// Room: shibanlu4.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "碎石小路");

	set("long", @LONG
这条碎石小路往北就是富贵山庄的后院了，南面是富贵如意厅，路上生满了青
苔，一不当心就会跌倒，两侧不知名的野花开得倒也茂盛，淡淡的散发着一种清新
的花香。草窠中偶尔传来一两声蟋蟀的叫声。一抬头，可以看见几个或是蜈蚣状，
或是老鹰状的风筝高高飞舞在蓝天白云中。
LONG
	);

	set("type","road");
	set("outdoors", "fugui");
	set("exits",([
		"south":__DIR__"fuguitin",
		"northeast":__DIR__"grass3",
		"northwest":__DIR__"grass1",
	]) );
        set("objects" , ([
	    __DIR__"obj/flower" : 1,
        ]));
	set("coor/x",10);
	set("coor/y",220);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}
