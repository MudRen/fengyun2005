// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "观星台");
        set("long", @LONG
这里便是最早的天文台遗址，位于登封县南十五里处，周公测景便发源于此，
便是在这里“求地中，测土深，正日影，以定四时季节”，确定了周代历法。观
星台内圭，量天尺，一应俱全。
LONG
        );
        set("exits", ([ 
  "northdown" : __DIR__"shizong",
]));
        set("objects", ([
                __DIR__"npc/zha" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
