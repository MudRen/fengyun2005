inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山村东首");
        set("long", @LONG
山村的东面还有两家店铺，一家门口有个很大的石磨盘，一头毛驴不紧不慢地
打着转儿，几个女人一边往磨盘里加豆子，一边嘻嘻哈哈地打闹，招牌上写着“欧
阳豆腐铺”。另一家门口则是个烧得通红的熔炉，几个赤裸着上身的汉子正在叮叮
当当地打铁。
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"vroad3",
	"east" : __DIR__"vroad5",
	"north" : __DIR__"tofupu",
	"south":  __DIR__"weaponstore",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",80);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
