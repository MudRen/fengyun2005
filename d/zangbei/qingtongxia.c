inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "青铜峡");
        set("long", @LONG
青铜峡位于二山之间，东是牛首山，西为贺兰山，和阗河从中穿峡而过，景色
迤逦。北面是著名的一百零八塔，两侧有一线天、魔窟、睡佛山、禹门口。只是此
地人迹罕至，盗贼横行，原来住着的几户人家不堪艰难，纷纷迁往他处，路旁只剩
下些残垣断壁。
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"shike",
		"northeast" : __DIR__"deserted",
		"south": __DIR__"kunlun1",
		"west": __DIR__"longmengxia",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",-500);
        set("coor/y",550);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	replace_program(ROOM);
}
