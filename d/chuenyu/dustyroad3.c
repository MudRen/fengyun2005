// Room: /d/chuenyu/dustyroad2.c

#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "青石小路");
        set("long", @LONG
这是一条通向一所民宅的青石小路。小屋就在你的东北方向。一个整洁的小草
坪在你的东边。西南方向是一个三叉路口，你似乎可以听到卖花姑娘清脆的叫卖声。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"southwest" : __DIR__"dustyroad2",
  		"northeast" : __DIR__"home",
  		"north" : __DIR__"smallyard",
	]));

        set("outdoors", "chuenyu");

	set("coor/x",-20);
	set("coor/y",-20);
	set("coor/z",-20);
	setup();

}

