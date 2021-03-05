
inherit ROOM;

void create()
{
	set("short", "小镇");
	set("long", @LONG
小镇不是很大，但却很繁华。因其在武当山脚，镇中既使几岁小童，也会几招
太极拳。小镇东边是桃花林，桃花林后据说还有个小村，当地人叫做[33m桃源村[32m，村人
甚少出外走动，也不知入口在那里。小镇再向南，就是鼎鼎大名的[33m武当山[32m。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"xzroad1",
		"north" : __DIR__"bwuroad2",
		"east" : AREA_TAOYUAN"taolin",
	]));
	set("outdoors", "wudang");
	set("objects", ([ 
		__DIR__"npc/xiaotong": 2 
	]) );
	set("coor/x",0);
	set("coor/y",100);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
