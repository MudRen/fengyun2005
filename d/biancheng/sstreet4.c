inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "南街尽头");
        set("long", @LONG
小街的繁华很快就到了尽头，往南看，远远可见一条湍急的河流。寒风卷起满
天黄沙。一朵残菊在风沙中打着滚，既不知是从哪里吹来的，也不知要被吹到哪里
去。世人岂非也都正如这瓣残菊一样，又有谁能预知自己的命运？
LONG
        );
        set("exits", ([ 
		"north": __DIR__"sstreet3",
		"southeast": AREA_ZANGBEI"bank",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",-40);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
