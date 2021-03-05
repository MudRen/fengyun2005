inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "娇娇客栈");
        set("long", @LONG
这里是小村里最大的，也是唯一的一家客店，老板娘据说是当年江湖上十大恶
人之一的屠娇娇，在大侠燕南天的感召下洗手做起生意来。过往的客人大多是慕名
投宿，想看看这个昔日易容之术已臻化境的“千面千身，不男不女“到底是什么模
样。
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"vroad2",
	"up" : __DIR__"jiaojiao2",
	]));
        set("objects", ([
		__DIR__"npc/xiaojiao":1,
	]) );
	set("coor/x",50);
        set("coor/y",70);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
