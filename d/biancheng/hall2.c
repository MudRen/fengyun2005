inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "万马堂大厅");
        set("long", @LONG
转过屏风，就是一间大厅。无论谁第一眼看到这大厅，都难免要吃一惊。大厅
虽然只不过有十来丈宽，简直长得令人无法想象。一个人若要从门口走到另一端去，
说不定要走上一两千步。
LONG
        );
        set("exits", ([ 
	"north" : __DIR__"hall3",
	"south": __DIR__"hall1",
	]));
        set("objects", ([
	]) );
        set("coor/x",-10);
        set("coor/y",110);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
