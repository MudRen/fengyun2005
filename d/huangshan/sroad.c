// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "石阶");
        set("long", @LONG
长长的石阶，沿途尽是茂林修竹和一些高大的松树，松枝上挂着云雾草，越发
增加了清凉幽静的感觉，和前面的险峻截然不同。石阶尽头是一座小庵堂，粉墙环
绕，庵前翠竹如海，诸潭环布，景色清幽至极。
LONG
        );
	set("exits", ([ 
  		"west" : __DIR__"feicui",
  		"northup" : __DIR__"caishi",
  		"east" : __DIR__"diezhang",
		"south" : __DIR__"songgu",
	]));

    set("outdoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",-30);
	set("coor/z",30);
	set("objects", ([
	__DIR__"npc/monkey1" : 1,
                        ]) );
	
	setup();
        replace_program(ROOM);
}
