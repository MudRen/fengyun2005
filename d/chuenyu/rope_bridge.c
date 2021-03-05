// Room: /d/chuenyu/rope_bridge.c

inherit ROOM;

void create()
{
// this place can check on player's dodge, if toolow, drop them!
        set("short", "铁索桥");
        set("long", @LONG
山顶强劲的风吹得铁索桥左右晃动，脚下的万丈深渊使你头晕目旋。你竭尽全
力的维持身体平衡。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"high_b_mtn",
  "east" : __DIR__"high_b_mtn2",
]));
        set("objects", ([
                __DIR__"npc/jiading3" : 2,
        ]) );


        set("outdoors", "chuenyu");

	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
