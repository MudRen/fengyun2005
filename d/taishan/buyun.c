// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","云步桥");
  set("long",@LONG
这是泰山中西交汇之处，四周峰峦叠嶂，山势险峻。云步桥高悬如虹，百丈崖
瀑布飞泄，特别是每当雨季来临，悬崖垂瀑，飞流如练，景色尤为壮观。“云桥飞
瀑”便成了人们千百年来讴歌不绝的揽胜之地。
LONG
  );
  set("exits",([
	"down" : __DIR__"zhongtian",
	"westup" : __DIR__"aolai",
	"northup" : __DIR__"wusong",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",70);
	setup();
  	replace_program(ROOM);
}
