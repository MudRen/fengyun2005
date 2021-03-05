inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "河谷");
        set("long", @LONG
穿越俄初山莽莽苍苍的原始森林，迎面是狭窄险峻、湍流飞瀑的河谷。一条小
路从这里蜿蜒伸向另一片原始森林，前面是佛教典籍中提到的地狱谷，传说是居住
在雪山上的神仙们惩治恶魔的地方，每当月黑风高时，杀人者的嚎叫与被杀者的哀
鸣总是让人寒毛倒竖。
LONG
        );
        set("exits", ([ 
		"northeast" : __DIR__"hellvalley3",
		"westup":  __DIR__"hellvalley1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1980);
        set("coor/y",620);
        set("coor/z",10);
	set("map","zbwest");
	setup();

}
