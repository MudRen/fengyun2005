// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "阿鼻狱");
        set("long", @LONG
又名穿鼻狱，来到这里的人下世绝无转生为人的可能，这里的人都象牛一样，
鼻孔被穿，无数牛头，马面牵之来回行走，不时以铜锤击身，钢鞭敲打，使其时刻
警醒。再下面便是最后一层秤杆狱。
LONG
        );
        set("exits", ([
		"up" : __DIR__"xuechi",
		"down" : __DIR__"banggan",
        ]) );
	set("no_fight",1);

	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-170);
	setup();
        replace_program(ROOM);
}
 
