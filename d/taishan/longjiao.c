// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","龙角山");
  set("long",@LONG
历代帝王多爱泰山封禅，历代勘舆之说，说泰山龙脉所系，龙角山便是龙角所
在，远看龙角山，其势雄浑，昂首群峰，虽不高，但俊挺入云的气势实在是无法企
及的，在龙角山上随处可见历代君王手植龙柏，更给泰山带来了一股霸王之气。
LONG
  );
  set("exits",([
	"eastdown" : __DIR__"jiunu",
               ]));
        set("objects", ([
        __DIR__"npc/chou" : 1,
	__DIR__"npc/mao" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",100);
	setup();
  	replace_program(ROOM);
}
