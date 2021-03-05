// Tie@fengyun
inherit ROOM;
void create()
{
    set("short", "阴暗石巷");
    set("long", @LONG
东地巷往前几步，有一条阴暗的石巷，巷里散发着一种奇怪的霉腐味道。又夹
杂着一丝血腥，和干净宽敞的东地巷格格不入。又脏又臭的小河沟顺着小巷侧缓缓
流淌，上面还漂着染满着黑血的绷带，令人闻之欲呕。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"yulong31",
	"north" : __DIR__"stone2",
	"east" : __DIR__"cheaph",
      ]));
    set("objects", ([
	__DIR__"npc/scavenger" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",240);
    set("coor/y",60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
