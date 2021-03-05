inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "寒梅谷");
        set("long", @LONG
寒梅谷是海子山东边的山溪小沟，全长二三十里。这里是个美丽的山谷，天空
澄蓝，积雪银白，梅花鲜红。山谷的一侧坐着几个穿着讲究的锦衣公子，似乎是在
赏雪。奇怪的是，地上有一个三尺宽，五尺深，七尺长的坑，坑边放着桌椅，上面
有食盒，还有两坛酒。
LONG
        );
        set("exits", ([ 
		"westup" : __DIR__"haizi",
	]));
        set("objects", ([
        	__DIR__"npc/qiu":	1,
        	__DIR__"npc/du":	1,
        	__DIR__"obj/hole":	1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2050);
        set("coor/y",560);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
