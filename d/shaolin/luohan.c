// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "罗汉堂");
        set("long", @LONG
少林名扬天下的罗汉堂，堂中墙壁上十八罗汉身姿各异，合而为罗汉十八手。
凡能进得罗汉堂的弟子，武功都为一时之选，可以入住僧兵院。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"jialan",
  "east" : __DIR__"bingeast",
  "west" : __DIR__"bingwest",
  "north" : __DIR__"damo",
]));
        set("objects", ([
                __DIR__"npc/master_19" : 1,
       ]) );
	set("coor/x",0);
	set("coor/y",80);
	set("coor/z",20);
	setup();

}
