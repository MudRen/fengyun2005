
inherit ROOM;
#include <room.h>
void create()
{
    set("short", "大牢");
	set("long", @LONG
这里是关押犯人的地方，从台阶上走下来是一条通道，通道两旁是石墙及木栅
栏隔成的小房间，里面关押着一些轻刑待审罪犯。甬道的东头又有阶梯通向下面。
不知从那里飘来的腐臭之气充斥着整个牢房。
LONG
	);
    	set("exits", ([ /* sizeof() == 3 */
        	"west" : __DIR__"dayu",
        	"north" : __DIR__"laofang1",
        	"south" : __DIR__"laofang2",
        	"eastdown" : __DIR__"andao1",
    	]));
	set("locked", 1);
    	set("indoors", "jinan");
	set("coor/x",40);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir){
	if((dir == "south" || dir == "north") && query("locked")) {
		return notify_fail("牢门上着锁，你没有办法进去。\n");
	}
	return 1;
}
