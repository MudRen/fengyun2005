// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "讲武堂");
        set("long", @LONG
这是达摩院的的长老们传授武功的所在，达摩院的名师大多在此处讲习。闲来无事的
时候，这里总有几个老僧在打扫屋子，没有人知道他们已经在这里住了多久了，连心湖方
丈也不知道他们的来历。
LONG
        );
        set("exits", ([ 
 		 	"east" : __DIR__"damo",
		]));
		set("coor/x",-10);
		set("coor/y",90);
		set("coor/z",20);
		setup();
}
