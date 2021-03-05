inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "密林");
        set("long", @LONG
树林并不浓密，白杨树宽大的叶子片片向上，几乎沒有斜生的，更不用說倒垂
了。树皮光滑而有銀色的晕圈，微微泛出淡青色。林间本没有路，走的人多了，便
踏出一条南北向的小径，站在这里，隐隐可以听见远处传来伐木人的吆喝。再往东
南走，白杨树逐渐被不知名的大树所代替，人迹更是稀少。
LONG
        );
        set("exits", ([ 
		"south": __DIR__"woods3",
		"west" : __DIR__"linchang2",
		"east":	__DIR__"forest1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1620);
        set("coor/y",680);
        set("coor/z",0);
	set("map","zbwest");
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
