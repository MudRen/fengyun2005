inherit ROOM;
void create()
{
        set("short", "南北大道");
        set("long", @LONG
这是风云城的一条主要大道。它上穿白山黑水，直达松花江。下接风云京都，
再通江南海口。干线上商旅不绝，正是东西和南北商道的交汇之处，路牌上写着：
    [33m西『三清山』  东『千佛山』  南『风云城』  北『冰封之镇』[32m
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"road5",
  "south" : __DIR__"road1",
  "east" : AREA_JINAN"road1q",
 "westup" : AREA_DAOGUAN"sroad",
]));
        set("outdoors", "laowu");
	set("coor/x",0);
	set("coor/y",-10040);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
