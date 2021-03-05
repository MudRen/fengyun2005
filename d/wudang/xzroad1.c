
inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
用青石板铺成的道路，打扫得干乾净净。几个小童在街道上互相追逐玩耍。街
道两旁是红砖砌成的房屋，两位老者悠闲地坐在家门前吸烟聊天。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"xiaozhen",
		"south" : __DIR__"xzroad2",
		"east" : __DIR__"xzdong",
        	"west" : __DIR__"xinghuacun",
	]));
	set("outdoors", "wudang");
	set("objects", ([ 
		__DIR__"npc/dog": 1,
		__DIR__"npc/xiaotong": 2 
	]) );
	set("coor/x",0);
	set("coor/y",90);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);

}
