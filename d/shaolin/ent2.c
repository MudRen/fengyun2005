// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山道");
        set("long", @LONG
青石阶到这一缓，抬头上望，已经可看见两座巨大的石坊，路边卖乡烛的山民
也越来越多，远远可以看见两个黄衣僧人，进香的游客来往穿梭，一派兴旺。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"ent3",
  "southdown" : __DIR__"ent",
]));
        set("objects", ([
                __DIR__"npc/xiangke" : 2,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",-120);
	set("coor/z",-40);
	setup();
        replace_program(ROOM);
}
