
inherit ROOM;

void create()
{
	set("short", "旧驿站");
	set("long", @LONG
早已废弃的风云驿站，破砖烂瓦多少给人种沧桑的感觉。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"wcloud2",
	]));
//	set("objects", ([
//		__DIR__"npc/officer": 1
//	]) );

	set("coor/x",-20);
	set("coor/y",10);
        set("coor/z",-300);
	setup();
}

