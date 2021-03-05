inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "天心阁");
        set("long", @LONG
天心楼不在天心，在湖心。冲古寺的西部有一湖，当地人称之为兴伊错，湖水
碧绿沉凝，鱼游其间；湖面宽阔，百鸟栖息。半顷翠波，倒映着楼上的朱栏，栏下
泊着几只轻舟，四面纱窗都已支起。夜色弥漫，楼内灯光闪耀，人影憧憧。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"temple1",
	]));
        set("objects", ([
	]) );
	set("coor/x",-1720);
        set("coor/y",650);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
