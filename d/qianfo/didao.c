// 地道
inherit ROOM;
void create()
{
        set("short", "地道");
        set("long", @LONG
黑漆漆的地道，你不知道要爬多久才能出去。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"maoroom1",
  "westdown" : __DIR__"didao1",
]));
	set("coor/x",90);
	set("coor/y",-100);
	set("coor/z",-35);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if( userp(me) && dir == "westdown")
                    message_vision("$N手脚并用，向地道深处爬去\n",me);

        return 1;
}

