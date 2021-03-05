inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "梅花庵外");
        set("long", @LONG
草色枯黄，夕阳凄凄惨惨照在油漆久已剥落的大门上。依稀还可以分辨出“[35m梅
花庵[32m”三个字。但是庵内庵外的梅花呢？难道那些倔强的梅树，在经历一场惨绝人
寰的血战后，终于发现了人类的残酷，也已觉得人间无可留恋，宁愿砍去当柴烧，
宁愿在火焰中化为灰烬？无论如何，这名庵犹在，但当年的英雄们，却已和梅花一
起，全部化作了尘土。
LONG
        );
        set("exits", ([ 
		"eastdown" : __DIR__"road2b",
		"enter": __DIR__"meihuaan2",
	]));
        set("objects", ([
		__DIR__"npc/m_nun" : 1,
	]) );
	set("coor/x",0);
        set("coor/y",20);
        set("coor/z",80);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
