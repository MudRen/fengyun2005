// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "武库");
        set("long", @LONG
白水宫内皆是女子，武功独特，所用武器也特地定做，专为女子打造，使将开
来，轻灵无比，姿态曼妙，房内陈设着几排兵器架，上面刀，枪，剑，指环，应有
尽有，最怪在于居然还有一盒绣花针，不知道有何用处。。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"yaofang",
]));
	set("coor/x",-10);
	set("coor/y",5);
	set("coor/z",0);
	set("objects", ([
        __DIR__"npc/needlegirl" : 1,
                        ]) );
	setup();
        replace_program(ROOM);
}
