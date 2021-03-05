
inherit ROOM;

void create()
{
	set("short", "农具店");
	set("long", @LONG
小小的一个农具店，屋里摆著各式各样的农具。左面墙上挂著几把镰刀，右边
墙角放著几把钉钯。中间一个大火炉，炉火正旺，一位驼背老人望著炉火呆呆的出
神。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"xzroad2",
	]));
        set("objects", ([
                __DIR__"npc/seller1" : 1,
        ]) );
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",-50);
	setup();
replace_program(ROOM);

}
