inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "水下暗道");
        set("long", @LONG
地下竞有条秘密的河流。借着灯火，才看出这条河流很窄而弯曲，却看不出水
有多深，也不知通向哪里。两旁是坚固的石壁，左边的石壁上，过几步就有个巨大
的铁环，挂着很粗的铁链，石壁上长着青苔，铁环也已生锈。
LONG
        );
        set("exits", ([ 
		"up":		__DIR__"mgarden",
		"north":	__DIR__"tunnel2",
	]));
        set("item_desc", ([
      		"铁环":		"这铁环已经生锈，看样子是用来栓船的。\n", 
      		"ring":		"这铁环已经生锈，看样子是用来栓船的。\n", 
      		"铁链":		"这铁环已经生锈，看样子是用来栓船的。\n", 
      		"chain":	"这铁环已经生锈，看样子是用来栓船的。\n", 
    	]));
        set("objects", ([
	]) );

        set("coor/x",-1280);
        set("coor/y",680);
        set("coor/z",-10);
	set("map","zbeast");
	setup();
}




