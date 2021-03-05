
inherit ROOM;

void create()
{
        set("short", "石像林");
        set("long", @LONG
走在石像之中，宛如走入了古代英雄的聚会中。石像有的向你露齿而笑，有的
向你怒目而视。突见一座石像双手插腰，当路而立，凸睛怒目，瞪视著道路。石像
旁还有一座幼童之像，笑嘻嘻地仰面而视，右手斜指，左手拿著一块牌子。

     道路不通，请君南行！
     白石黑字，字迹分明。

LONG
        );
        set("exits", ([ 
  "north" : __DIR__"black2",
  "south" : __DIR__"naibridge",
  "east" :  __DIR__"grass",
]));
        set("outdoors", "palace");

	set("coor/x",-90);
	set("coor/y",70);
	set("coor/z",10);

	setup();
        replace_program(ROOM);
}

