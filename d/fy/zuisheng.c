inherit ROOM;
void create()
{
    set("short", "醉生小馆");
    set("long", @LONG
这里卖最烈也是最劣的白酒。一杆已经被风扯裂的酒旗上画着一个用红圈起来
的“酒”字。几根竹竿撑着一块业已变黑的白帆布，白布下放着几张破旧的木桌和
方凳，木桌上零零散散地放着几双木筷和几个崩了口的小碟儿。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"lssquare1",
      ]));
    set("objects", ([
			__DIR__"npc/wineowner" : 1,
			"/obj/npc/inform_beggar":1,
      ]) );

    set("coor/x",120);
    set("coor/y",100);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
