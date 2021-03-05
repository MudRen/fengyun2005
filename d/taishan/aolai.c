// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","傲崃峰");
  set("long",@LONG
到傲崃峰，黑龙潭美景尽收眼中，“长寿桥”凌空翱，弧形桥势如长虹，给峡
谷增添了婉约多姿的一景。桥下和溪右有三处百丈悬崖，每当夏秋雨季，瀑布从天
而降，飞珠溅玉，声若雷鸣，尤如白龙探涧，有“云龙三现”之称。瀑布奔流千年，
冲出了一个诺大的黑龙潭。成为泰山西之第一景。
LONG
  );
  	set("exits",([
		"eastdown" : __DIR__"buyun",
               ]));
        
        set("objects", ([
        	__DIR__"obj/lake2" : 1,
		"/obj/npc/scavenger" : 3,
        ]) );
        
        set("outdoors", "taishan");
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",80);
	setup();
  	replace_program(ROOM);
}
