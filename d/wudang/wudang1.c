
inherit ROOM;

void create()
{
	set("short", "武当前院");
	set("long", @LONG
大院中种著几株参天松树，更显得武当派的历史悠久。青石板铺成的地面，已
有了年代的痕迹。大院的尽头是几级白玉石台阶，上了台阶就是武当紫霄宫。左边
则是一条青石小路，通往后面。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"zhixiao",
		"west" : __DIR__"lingxuyan",
		"northeast" : __DIR__"wuroad1",
		"out" : __DIR__"wudang",
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
