
inherit ROOM;

void create()
{
	set("short", "凌虚岩");
	set("long", @LONG
凌虚岩清丽幽深，与世隔绝。相传唐代陈抟曾隐居于此。他致力于内功的研究，
练就了著名的睡功：五龙睡法。传说他一睡可百天不醒。至今南岩宫墙壁上还有陈
抟亲手所书横卧着的“福寿”二字。人称“卧福睡寿”。这儿有几个持剑的小童正
在操练着武当的“四象阵“，四人同进同退，攻守皆宜。
LONG
	);
	set("exits", ([
		"east" : __DIR__"wudang1",
	]));
	set("outdoors", "wudang");
		set("objects", ([
		__DIR__"npc/swordboy1" : 1,
		__DIR__"npc/swordboy2" : 1,
		__DIR__"npc/swordboy3" : 1,
		__DIR__"npc/swordboy4" : 1,
	]));
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
