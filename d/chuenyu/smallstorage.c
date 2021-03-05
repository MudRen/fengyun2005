
inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long", @LONG
这是一个简陋的小厨房。四壁已被油烟薰的分不出原来的颜色。墙上挂满了风
干了的卤肉，可是上面显然有着被老鼠咬过的痕迹。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"home",
]));
        set("objects", ([
                __DIR__"npc/rat" : 6,
        ]) );

	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",-20);
	setup();
}

