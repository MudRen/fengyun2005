// street2.c

#include <room.h>
inherit ROOM;
void create()
{
  set("short","斜阳道");
  set("long",@LONG
绕过大明湖，往东北而行，便是一条宽敞的石板路，历经沧桑，石板早已坑坑
洼洼，道旁静静立的是三三两两的老槐树，一个落魄寥落的文人在路上踟躇而行，
一匹瘦马跟在主人身后。往东北远眺，那连绵不断的山峦便是东岳泰山了。
LONG
  );
  set("exits",([
         "southwest":__DIR__"lake",
         "northeast":__DIR__"road2",
               ]));
        set("objects", ([
                __DIR__"npc/sadguy" : 1,
                __DIR__"npc/shouma" : 1,
       ]) );
    set("outdoors", "jinan");
	set("coor/x",30);
	set("coor/y",100);
	set("coor/z",0);
	setup();
    replace_program(ROOM);

}

