// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "天南中门");
        set("long", @LONG
这里的地面凸凹不平，但很干燥。路的两边放了几盆栽花，虽然这里缺少阳光
但由于有人精心料理花的长势实很茂盛。条石路从这里南北展开，根本看不到尽头。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tt",
  "south" : __DIR__"tnzl",
]));
        set("objects", ([
        __DIR__"obj/flowerpot": 1,
                        ]) );
        set("indoors", "cave");
	set("coor/x",4);
	set("coor/y",-6);
	set("coor/z",0);
	setup();
}
void reset()
{
        object          *inv;
        object          con, item;
        int             i;
        ::reset();
        con = present("flowerpot", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/bloodflower");
                item->move(con);
                item = new(__DIR__"obj/bloodflower");
                item->move(con);
        }
}


int valid_leave(object obj, string dir){
	object ma;
	if(dir == "north"){
		if( !obj->query("m_killer/毛战") || !obj->query("m_killer/毛野") ){
			return notify_fail("你探头探脑地向前面看了看,犹犹豫豫地停住了脚步。\n");
		}
	}	
	return 1;
}
