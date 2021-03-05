inherit ROOM;

void create()
{
	object box, matter;
        set("short", "八角街");
        set("long", @LONG
城市赤如皮革，有光滑美丽的一面，也有粗糙丑陋的一面。这段八角街上垃圾
粪便狼藉。成群结队的年老乞丐，穿着破旧褴褛的衣服，剃光头打赤足，匍匐在尘
土中，等待着行人香客的施舍。
LONG
        );
        
        set("exits", ([ 
		"north" : __DIR__"octo11",
		"south" : __DIR__"octo9",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"obj/trash" : 1,
		__DIR__"obj/junkstaff" : 1,
        ]) );
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        box = present("trash", this_object());
        matter = present("staff", this_object());
	matter->move(box);
}