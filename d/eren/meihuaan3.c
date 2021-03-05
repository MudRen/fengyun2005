inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "梅花庵");
        set("long", @LONG
大殿里一片阴森黝黑，看不见香火，也看不见诵经的人。香灯里早已长满了铜
绿，低垂的神幔后，那尊垂眉敛目的佛像，看来也充满了愁苦之意。她是为了这里
香火的冷落而悲悼？还是为了人类的残酷愚昧？
LONG
        );
        set("exits", ([ 
		"south": __DIR__"meihuaan2",
	]));
        set("objects", ([
		__DIR__"npc/liaoyin" : 1,
	]) );
	set("coor/x",-10);
        set("coor/y",25);
        set("coor/z",80);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
