
inherit ROOM;

void create()
{
	set("short", "滴水檐");
	set("long", @LONG
庭院深沉，浓荫如盖。木叶深处有蝉声摇曳，却衬得天地间更是寂静，红尘中
的嚣闹烦扰，似已长久未入庭院。
LONG
	);
	set("exits", ([
		"north" : __DIR__"wuroad1",
		"south" : __DIR__"qiongtaiguan",
	]));
	set("outdoors", "wudang");
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
