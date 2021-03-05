// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "钟楼");
        set("long", @LONG
到了这里，光线有所好转，因为四周墙壁之上都开了个小小窗户，和前两层大
不相同，墙上壁画早已脱落，几个僧人正在重新绘制，看来都是丹青妙手。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"zhonglou4",
  "down" : __DIR__"zhonglou2",
]));
		        set("objects", ([
                __DIR__"npc/monk52_sentry" : 1,   
       ]) );
	set("coor/x",20);
	set("coor/y",-60);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
