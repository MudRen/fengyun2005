// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "背阴山");
        set("long", @LONG
地藏殿后门出来，忽然阴风刺骨，原来到了背阴山，背阴山乃地府最险恶的地
方，漫山遍野皆是孤魂野鬼，形多凹凸，山势险峻，峻如蜀岭，高似庐岩，你不由
得硬着头皮往前走。
LONG
        );
        set("exits", ([
		"northdown" : __DIR__"dizang",
		"southdown" : __DIR__"shandao",
        ]) );
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",10);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
