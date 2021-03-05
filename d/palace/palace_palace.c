
inherit ROOM;

void create()
{
        set("short", "仙人洞");
        set("long", @LONG
帝王谷的一侧另有一条小路，小路旁有一个石洞。进入石洞，只见佳木茏葱，
奇花烂熳，一带清流，从花木深处泻于石隙之下。俯而视之，但见清溪泻玉，石
笋穿云，白石为栏，环抱池沼，石桥三港，兽面吞吐。
LONG
        );
        set("exits", ([ 
  		"southdown" : __DIR__"palace_front",
	]));
        set("objects", ([
               __DIR__"npc/master2" : 1,
       ]) );
        set("valid_startroom", 1);
	set("coor/x",-120);
	set("coor/y",130);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}

