
inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
你的面前猛然一亮，白炽的阳光照的人几乎睁不开眼来，这儿一个不小的山谷，
山洞便是唯一的入口。谷里鸟语花香，仿似来到了世外桃源。山坡和谷地中布满磷
峋古怪的巨石，远远望去，像是一大把珍珠撒在绿色的海洋上。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"grassland1",
  "south" : __DIR__"hole3",
]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
