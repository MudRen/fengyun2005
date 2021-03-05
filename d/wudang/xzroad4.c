
inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
用青石板铺成的道路，打扫得干乾净净。几个小童在街道上互相追逐玩耍。街
道两旁是红砖砌成的房屋，不远处可以遥遥望见一座不算很高的青色山冈。
LONG
	);
	set("exits", ([ 
        "northwest" : __DIR__"xzroad3",
        "southeast" : "/d/bawang/shanlu",
        "east" : "/d/bawang/mantoudian",
	]));
	set("outdoors", "wudang");
	set("coor/x",60);
	set("coor/y",30);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
