// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","樱桃崖");
  set("long",@LONG
山势如黛，颜色俏丽，别处或青或黄，大不相同，泰山居民处高山，水果极为
难得，而樱桃易植且好吃，此处地处山阳，樱桃漫山遍野，每当樱桃成熟季节，满
山粉红，景致嫣然，游人到此，多爱买些，泰山樱桃得天地钟爱，与别处大是不同。
LONG
  );
  set("exits",([
	"southdown" : __DIR__"luohan",
               ]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",60);
	setup();
  	replace_program(ROOM);
}
