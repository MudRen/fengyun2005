// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","瞻鲁台");
  set("long",@LONG
此处便是泰山天街极东，向下远眺，齐鲁大地尽收眼低，所以名为瞻鲁台，台
上一座凉亭，供人稍作歇息。
LONG
  );
  set("exits",([
	"west" : __DIR__"bixia",
	"north" : __DIR__"riguan",
               ]));
        set("outdoors", "fengyun");
    
        
	set("coor/x",30);
	set("coor/y",20);
	set("coor/z",120);

	set("objects", ([
               __DIR__"npc/shengdaniang" : 1,
                        ]) );


	setup();
  	replace_program(ROOM);
}
