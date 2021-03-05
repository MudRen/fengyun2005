// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "方丈");
        set("long", @LONG
此乃寺中主持方丈的居所，前檐悬大钟一口，重达六百余斤，此室当年乾隆曾
住过，所以又称“龙庭”。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"fangnan",
  "northup" : __DIR__"lixue",
  "east" : __DIR__"kuoran",
  "west" : __DIR__"fangtui",
]));
        set("objects", ([
                __DIR__"npc/master_17_1" : 1,
       ]) );
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
