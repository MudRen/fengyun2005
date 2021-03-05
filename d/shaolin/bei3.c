// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "碑林");
        set("long", @LONG
一行碑多为历代书法名家所书，记载少林千年沧桑，其中以米芾的“[33m第一山[32m”
为最，当属稀世之宝。其余“[33m三十六峰赋[32m”等也口碑不绝，是少林四行碑中最具观
赏价值的一行。再往东便是碑林的最后一行。
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"bei4",
  		"southwest" : __DIR__"yingbi",
	]));
        set("objects", ([
                BOOKS"skill/zen_50" : 1,
                BOOKS"skill/buddhism_50" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",10);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
