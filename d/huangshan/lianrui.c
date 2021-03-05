// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "莲蕊峰");
        set("long", @LONG
与莲花峰相互依托，这里恰似莲花之蕊，峰不高，树木也不多，可怪石林立参
差不齐，高低起伏，甚是难走，而且并无胜景，所以游人罕至。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"yuping",
]));
        set("objects", ([
        __DIR__"obj/guai" : 1,
        "/d/taoyuan/npc/rabbit" : 2,
                        ]) );

        set("outdoors", "huangshan");
	set("coor/x",-60);
	set("coor/y",-20);
	set("coor/z",40);
	setup();
}
