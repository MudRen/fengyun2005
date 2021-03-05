
inherit ROOM;

void create()
{
        set("short", "密道");
        set("long", @LONG
拨开道旁的杂草，你惊讶地发现后面竟然有人走过的迹象，道边高达丈许的灌
木丛形成了天然的屏障，再加上地势渐低，没人注意到这里竟会有路，更无人可以
猜到此路倒底通向何方。前面居然还有一个山洞。
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"smallroad4",
  		"west" : __DIR__"cave_tunnel",
	]));
        set("outdoors", "resort");
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

