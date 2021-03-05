// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "鼓楼");
        set("long", @LONG
进得这里，光线突然暗了下来，只有幽幽的烛光在闪烁着，屋角一块铜碑，立
有“铸造铜弥勒碑记”。
LONG
        );
        set("exits", ([ 
		  "up" : __DIR__"gulou2",
		  "east" : __DIR__"dianjiao",
		  "south" : __DIR__"yewest",
		]));
        set("objects", ([
                __DIR__"obj/tong" : 1,
                 __DIR__"npc/monk5" : 1,	
       ]) );
		set("coor/x",-10);
		set("coor/y",-60);
		set("coor/z",-10);
		setup();
        replace_program(ROOM);
}
