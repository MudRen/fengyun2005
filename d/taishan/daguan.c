// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","大观峰");
  set("long",@LONG
说是峰，其实是一段崖壁，壁前一块平坦开阔的石坪，壁上琳琅满目的摩崖石
刻使无数游人留步驻足，其中《纪泰山铭》碑相传为唐玄宗手书，洋洋千言，字体
俊逸雄浑，开书法唐隶一格，被誉为“自汉以来碑碣之雄壮未有及者”。
LONG
  );
  set("exits",([
	"southwest" : __DIR__"bixia",
               ]));
        set("outdoors", "fengyun");
        set("objects", ([
        "/d/taoyuan/npc/rabbit": 2,
        ]) );

        
	set("coor/x",25);
	set("coor/y",25);
	set("coor/z",120);
	setup();
  	replace_program(ROOM);
}
