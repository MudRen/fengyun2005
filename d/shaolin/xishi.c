// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "西石坊");
        set("long", @LONG
始建明嘉靖年间，题额“大乘佛地”，对联为“心传古洞，严冬雪拥神光膝；
面壁高峰，静夜风闻子晋笙”，西面题额“嵩少禅林”，一幅对联正是“双双玉井，
碧澄冷浸千秋月；六六玄峰，翠耸光连万壑云”
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"ent3",
]));
        set("objects", ([
                __DIR__"obj/west_shi" : 1,
                __DIR__"npc/monk3" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",-30);
	setup();
        replace_program(ROOM);
}
