// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "药房");
        set("long", @LONG
白水殿侧便是药房，周围护卫来回巡视，看上去武功皆不弱，虽然白水宫难于
发现，但这里还是戒备森严，重要性可见一斑．白水宫不仅武功独特，用毒解毒也
是天下知名，屋中四个红木柜子，各自分门别类备有天下名药，毒药，解药。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"gong",
  "north" : __DIR__"wuku",
]));
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
