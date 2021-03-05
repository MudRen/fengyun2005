// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "孙记铁铺");
        set("long", @LONG
一个门面乌黑的小店，一尺多高的门槛似乎已经被客人们踩平了。门口立着一
块招牌，上面写着：
	孙 记 铁 铺： 专卖各类生熟铁块，武器原料
LONG
        );
        set("exits", ([ 
  		"northeast" : __DIR__"dengfeng",
	]));
        set("objects", ([
                __DIR__"npc/tie_waiter" : 1,
        ]) );
	set("coor/x",-610);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
