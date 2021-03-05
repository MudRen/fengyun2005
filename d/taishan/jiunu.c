// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","九女峰");
  set("long",@LONG
九女峰峰如其名，远观宛数位妙龄女子轻歌曼舞，据传这便是天上仙女来凡间
游玩的地方，雄浑的山在这里特别的温柔，淡淡的一抹清泉，随着溪流的浅吟，缓
缓的滑落，给九女峰围上一条玉带，远看各小上头，仙女或低吟，或浅笑，或佯嗔，
天地造化实在不同凡响。
LONG
  );
  set("exits",([
	"eastdown" : __DIR__"wusong",
	"westup" : __DIR__"longjiao",
               ]));
        set("objects", ([
        __DIR__"npc/pettrainer4" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",90);
	setup();
  	replace_program(ROOM);
}
