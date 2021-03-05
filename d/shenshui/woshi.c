// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "裨女卧室");
        set("long", @LONG
这是宫中裨女的卧室，轻罗帐，绿牙床，屋中陈设不多，但全部恰到好处，正
中的桌上一个青瓷官窑花瓶中错落有致的插着几束刚刚采来的野花，为屋子平添了
一丝春意。
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"gong",
  "east" : __DIR__"woshi2",
]));
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
