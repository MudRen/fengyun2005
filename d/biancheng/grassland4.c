inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "草场");
        set("long", @LONG
暮春三月，羊欢草长，这里是万马堂放牧的草场，恰似一块绿色的翡翠镶嵌在
无边无际的荒原之中。大草原上，正响起了一片牧歌，“天苍苍，野茫茫，风吹草
低见牛羊。”没有牛羊，只有马。马群在阳光下奔驰，天地间充满了生命的活力。
草场的南面有一个了望台矗立在土丘上。
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"grassland5",
		"south": 	__DIR__"sentry",
		"west":		__DIR__"grassland3",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",110);
        set("coor/y",80);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
