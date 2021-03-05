inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "林间空地");
        set("long", @LONG
往前走仍然是无边无际的林子，并不浓密，偶尔可以见到伐木人留下的篝火，
或是一块块只留下树根的空地。面前就是这么块空地，奇怪的是，空地中央竟然摆
着张小桌子。桌子上摆着些纸人纸马，还有一柄纸刀。用白纸糊成的刀，但刀柄却
涂成了黑色。没有人声，只有箫杀之意。空地旁有一间小屋。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"woods2",
		"south" : __DIR__"woodcabin",
	]));
        set("item_desc", ([
        	"table": "一张桌子上摆着些纸人纸马，还有一柄纸刀。用白纸糊成的刀，但刀柄却涂
成了黑色。\n",
        	"桌子" : "一张桌子上摆着些纸人纸马，还有一柄纸刀。用白纸糊成的刀，但刀柄却涂
成了黑色。\n",
        
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1620);
        set("coor/y",670);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	create_door("south","door","木门","north",DOOR_CLOSED);
}
