#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "弱水沉沙");
	set("long", @LONG
你就好像落在了空处，不停地下沉。周围虽然是缕缕流动的沙，可是你无处着
力，根本浮不上来，你就象周围的沙粒一样不停地沉下去，沉下去。。。四周的流
沙不停的挤过来，让你有一种近乎窒息的感觉。 
LONG
	);
	set("exits", ([ 
  		"down" : __DIR__"sandriver",
	]));

	set("indoors", "quicksand");

set("coor/x",-1060);
	set("coor/y",-10);
	set("coor/z",-30);
	setup();
}
