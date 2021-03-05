inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "万马堂右厅");
        set("long", @LONG
无论谁第一眼看到这大厅，都难免要吃一惊。大厅虽然只不过有十来丈宽，简
直长得令人无法想象。一个人若要从门口走到另一端去，说不定要走上一两千步。
大厅右边的粉墙上，写着三个比人还高的大字“万马堂”，墨渍淋漓，龙飞凤舞。
LONG
        );
        set("exits", ([ 
	"west": __DIR__"hall3",
	]));
        set("objects", ([
	]) );
        set("coor/x",-5);
        set("coor/y",120);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
