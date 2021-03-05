inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "庵院");
        set("long", @LONG
走上铺满苍苔的石阶，轻轻一推，残败的大门就“呀”的一声开了，那声音就
像是人们的叹息。院子里的落叶很厚，厚得连秋风都吹不起。一阵阵低沉的诵经声，
随着秋风，穿过这荒凉的院落。昔日香火茂盛的梅花庵，象十九年前的血案，慢慢
地已被世人遗忘。
LONG
        );
        set("exits", ([ 
		"out": __DIR__"meihuaan",
		"north": __DIR__"meihuaan3",
	]));
        set("objects", ([
		
	]) );
	set("coor/x",-10);
        set("coor/y",20);
        set("coor/z",80);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
