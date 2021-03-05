
inherit ROOM;

void create()
{
	set("short", "人间道");
	set("long", @LONG
这是一条狭窄的山道,向着北方一座山峰行去。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"northup"   : __DIR__"renjiandao2",
        "southdown" : __DIR__"kongdi",
	]));
        set("objects", ([
        __DIR__"npc/wei-shi3": 1,
	]) );
      set("outdoors", "bat");
	set("coor/x",-20);
	set("coor/y",-20);
	set("coor/z",40);
	setup();
}

/*
int valid_leave(object me, string dir)
{
        object ob;
        if( dir == "northup" && ob=present("wu shi", this_object()))
        {
                return notify_fail("这个方向的路被"+ob->name()+"挡住了 。\n");
        }
                return 1;
}
*/