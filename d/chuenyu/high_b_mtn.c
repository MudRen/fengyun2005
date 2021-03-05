// Room: /d/chuenyu/foot_b_mtn.c

inherit ROOM;

void create()
{
        set("short", "黑松山顶");
        set("long", @LONG
往山脚望去，你依稀的看到乡村里的袅袅炊烟。山路在这里转了个弯，向东面
延伸过去。再往东走，是一座令人望而止步的铁索桥，横跨在万丈峭壁之上。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"foot_b_mtn2",
  "east" : __DIR__"rope_bridge",
]));

	set("objects", ([
                __DIR__"npc/jiading2" : 2,
		"/obj/npc/trashcan" :1,
	]) );

        set("outdoors", "chuenyu");

	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
