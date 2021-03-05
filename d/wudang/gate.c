
inherit ROOM;

void create()
{
	set("short", "武当山门");
	set("long", @LONG
一座巍巍的山门，上面书写着[33m『武当山』[32m几个苍劲的大字。武当山又名太和山，
峰奇峦秀，涧险岩危，自古就被誉为“天下第一仙山”。唐代起，几乎历代皇帝都
极力扶植武当道教，到明朝，武当山以“治世玄岳”的崇高地位成为全国道教的活
动中心。远远望去，但见群峰挺立，卓立云海。
LONG
	);
	set("exits", ([
		"north" : __DIR__"road1",
                "southup" : __DIR__"road2",
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
