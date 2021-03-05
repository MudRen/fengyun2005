inherit ROOM;
void create ()
{
        set ("short", "阴暗小路");
        set ("long", @LONG
这是一条阴暗潮湿的小路，位于沉香城之西南，周围散落着一些残垣断壁，路
边杂草丛生。由于官府很少管这里，所以治安并不十分好。到处是沉闷的灰色，不
见一丝生机。向西望去，一个天然的宽阔平台近在眼前。
LONG);
        set("exits", ([ //sizeof() == 4
                "north" : __DIR__"yinroad2",
        "westup" : __DIR__"bigstage",
        ]));
        set("type", "road");
       set("outdoors", "wolfmount");
	set("coor/x",30);
	set("coor/y",70);
	set("coor/z",-60);
        setup();
	replace_program(ROOM);
}
