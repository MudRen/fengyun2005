// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "修身堂");
        set("long", @LONG
达摩院乃讲授言行，处世之道的地方，少林为武林第一名门正派，座下弟子大
多言行正派，绝少败类，便都是这里的功劳。少林弟子出山门之前都必须来此听大
法师说法。方可闯木人巷。
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"cj",
  "northwest" : __DIR__"banruo",
]));
        set("objects", ([
                __DIR__"npc/master_18b" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",110);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
