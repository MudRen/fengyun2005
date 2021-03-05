// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "青鸾桥");
        set("long", @LONG
倚着山跨越着一座石梁，看上去象是一座桥，远远望去，又好似青鸾腾空，背
上可以行人，石梁左侧刻有“青鸾”二字。石梁两头的岩石堆中各长有几棵松树，似
隔桥相望的游人。整个石梁乃一块巨石，虽年代久远却毫无裂缝，上面寸草不生。
LONG
        );
	set("exits", ([ 
  		"eastup"  : __DIR__"taohua",
  		"south" : __DIR__"renzi",
  		"southwest" : __DIR__"zuishi",
  		"north" : __DIR__"baizhang",
  		"westup" : __DIR__"mroad2",
	]));
    set("objects", ([
    	__DIR__"obj/stone" : 1,
    	__DIR__"obj/stone4" : 1,
    	__DIR__"npc/monkey2" : 1,
    ]) );
    
    set("outdoors", "huangshan");
	set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",10);
	setup();
}

void reset () {
    object *inv;
    object item1, stone4;
    ::reset();
    
    stone4 = present("stone", this_object());
    inv = all_inventory(stone4);
    if( !sizeof(inv) ) {
    	item1 = new(__DIR__"obj/shier");
        item1->move(stone4);
    }   
}
