inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "俄初山");
        set("long", @LONG
藏语中俄初山的意思就是闪光的山，山势平缓、覆盖着茫茫原始森林，秋季层
林尽染，万山红遍，在阳光下闪闪发光。登上山顶远眺，西南的海子山湖泊山峰交
错，东部翻过又长又深的地狱谷，就能到达传说中的神山贡嘎日松贡布雪峰。北面
山脚下赤土河的对岸就是边城。
LONG
        );
        set("exits", ([ 
		"northdown" : __DIR__"zhihuo",
		"southwest":  __DIR__"valley1",
		"eastdown":		__DIR__"hellvalley1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2020);
        set("coor/y",620);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
