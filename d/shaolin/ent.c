// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山道");
        set("long", @LONG
脚下石阶越来越陡，两边松涛盈耳，由此向上便是天下武学发源地禅宗祖庭--
嵩山少林寺，看着道路两边的美景，脚步不由快了起来，台阶已经没有多少级了。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"ent2",
  "southeast" : AREA_SONGSHAN"shaoshi",
]));
        set("objects", ([
                __DIR__"npc/xiangke" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",-130);
	set("coor/z",-50);
	setup();
        replace_program(ROOM);
}
