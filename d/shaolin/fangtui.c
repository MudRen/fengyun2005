// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "方丈退居");
        set("long", @LONG
这是前任方丈让位后的住所，到这里的方丈多以妙悟禅机，佛法造诣，武学修
为必都上参天理，学究天人，可惜多爱游历，穷山水之乐，据说只有每年正月期间，
藏经阁说法之后才会在这里住上一段时间。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"fang",
]));
        set("objects", ([
                __DIR__"npc/master_15" : 1,
		__DIR__"npc/master_16" : 1,
       ]) );
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
