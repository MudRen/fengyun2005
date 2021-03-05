// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","壶天阁");
  set("long",@LONG
壶天阁的存在似乎是非常的难以置信，虽然只是一小小阁楼，但是在千百年前，
那许多土木砖石来到半山之中，实在是不可思议，阁的精美华丽自不待言，真正的
美景还是自斗母宫以来直至中天门的柏洞，在这里尽收眼底，山路两侧，古柏树冠
相接，枝叶遮天，人行其间，如入洞府。天地灵气，尽在其中。
LONG
  );
  set("exits",([
	"down" : __DIR__"doumu",
	"up" : __DIR__"butian",
	"northeast" : __DIR__"yanghuang",
               ]));
        set("objects", ([
        __DIR__"npc/xue" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",40);
	setup();
  	replace_program(ROOM);
}
