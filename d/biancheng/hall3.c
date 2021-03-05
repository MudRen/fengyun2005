inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "万马堂大厅");
        set("long", @LONG
大厅中央，只摆着张白木长桌，长得简直像街道一样，竟可以容人在桌上驰马。
桌子两旁，至少有三百张白木椅。你若未到过万马堂，你永远无法想象世上会有这
么长的桌子，这么大的厅堂！
LONG
        );
        set("exits", ([ 
	"north" : __DIR__"hall4",
	"south": __DIR__"hall2",
	"west": __DIR__"hall3w",
	"east": __DIR__"hall3e",
	]));
        set("objects", ([
	]) );
        set("coor/x",-10);
        set("coor/y",120);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
