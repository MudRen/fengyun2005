inherit ROOM;
void create()
{
        set("short", "大宅院二楼");
        set("long", @LONG
这所大宅院是镇上唯一几幢像样的房子之一，原来住的是一个寡妇，常笑来后
寡妇就被赶回了娘家，大宅院改成了常笑的临时官邸。二层是卧室，比第一层更凸
向街面，透过两排落地的长窗可以望见小巷对面的鹦鹉楼，也可以把镇上唯一的几
条巷子看得一清二楚，这也是常笑看中这里的原因。
LONG
        );
        set("exits", ([ 
		"down":	__DIR__"house3",
		"east":	__DIR__"house3d",
	]));
	set("objects", ([
        	__DIR__"npc/changxiao" : 1,
        ]) );

        set("item_desc", ([
	
	 ]));
	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",10);
	set("map","taiping");
	setup();
}
