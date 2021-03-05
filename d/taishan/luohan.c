// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","罗汉崖");
  set("long",@LONG
泰山历来供奉的是道家神主，自佛教传入中土以来，泰山以雄浑气势吸引无数
礼佛之士，罗汉崖即为佛众钟爱之地，无数僧人在此苦修正果，终于出一罗汉，舍
身为人，普渡众生，泰山脚下，乡民受惠甚众，便把这处所在称为罗汉崖。
LONG
  );
  set("exits",([
	"northdown" : __DIR__"jingshi",
	"northup" : __DIR__"yingtao",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",50);
	setup();
  	replace_program(ROOM);
}
