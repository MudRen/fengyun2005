// Room: /d/chuenyu/dungeon.c

inherit ROOM;

void create()
{
        set("short", "刑房");
        set("long", @LONG
你处在一个阴湿的地牢里。地牢的角落里堆着一些干草，干草上沾满了暗红色
的血迹。许多骷髅被生锈的铁链绑在墙上。偶尔之间，你还可以听到老鼠“吱吱”
的尖叫声。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"northwest" : __DIR__"tunnel3",
  		"north"   : __DIR__"tunnel4",
	]));

	set("objects", ([
                __DIR__"npc/chuenyu" : 1,
		__DIR__"npc/xiaojuan2" : 1,
	]) );

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
