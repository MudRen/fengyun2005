// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山洞秘道");
        set("long", @LONG
转了几个弯，入洞已深，面前伸手不见五指，周围不时传来小动物掠过的沙沙
声，令人生畏。你想回头却已不知来时的道路。在这里你也分不清东西南北，只好
揣测着方向，壮着胆子摸索着往前走。
LONG
        );
   set("exits", ([ 
      "north" : __DIR__"midao6",
      "east" : __DIR__"midao2",
   ]));
	set("coor/x",90);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
