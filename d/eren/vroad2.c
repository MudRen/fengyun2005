inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山村道");
        set("long", @LONG
沿着青石小路向前走，路旁的屋舍越来越多，不觉已快到山村的中心。右首的
店门大开，门里似有酒菜的香味透出，走出的人个个油光满面打着饱嗝儿。左首有
幢精致的二层小楼，金黄色的琉璃瓦在日光下闪闪发光，招牌上写着四个龙飞凤舞
的大字“娇娇客栈“，旁边还挂着一个红灯笼。
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"vroad1",
	"east" : __DIR__"vroad2a",
	"north" : __DIR__"jiaojiao1",
	"south" : __DIR__"hahalou1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",50);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
