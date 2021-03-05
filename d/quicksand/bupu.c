// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "丰号布铺");
        set("long", @LONG
登封县城中的小店，外表不很起眼，但一看就是待客如宾的地方。一块黄绸的
幡子随风飘荡，上面绣着两行红色的大字：
	丰 号 布 铺：　专卖各类成衣原料
LONG
        );
        set("exits", ([ 
  	"northwest" : __DIR__"dengfeng",
	]));
        set("objects", ([
                __DIR__"npc/bu_waiter" : 1,
       ]) );
	set("coor/x",-590);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
