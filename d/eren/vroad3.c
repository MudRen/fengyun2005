inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山村道");
        set("long", @LONG
走过集市口，两旁冷清了许多，街上打扫得干干净净，没有一点浮土。除了普
通的村民，路上偶尔也会有衣冠华丽的行人，但个个神色匆忙。小路右首的招牌上
挂着“南宫钱庄”的旗号，左首黑漆漆的门面上写一个很大的“当”字。
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"vroad2a",
	"east" : __DIR__"vroad4",
	"south" : __DIR__"bank",
	"north" : __DIR__"pawnshop",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",70);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
