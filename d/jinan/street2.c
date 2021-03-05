// street2.c

#include <room.h>
inherit ROOM;
void create()
{
  set("short","观川亭");
  set("long",@LONG
济南大街上这个富丽堂皇的亭子，据说是当年丐帮老帮主任慈出资修葺而成，
以便来往路人遮风挡雨。立于此亭，看着远方汩汩流动的江河，文人雅客突发奇想，
名此亭为“观川亭”，取意自夫子的『逝者如斯夫』。西面几幢格调清雅的别墅是
[33m丐帮[32m在济南城修建的总堂。向东绕过大明湖，便是通向五岳之首[33m『泰山』[32m的山道。
LONG
  );
  set("exits",([
         "north":__DIR__"street1",
         "southup":__DIR__"street3",
         "west":__DIR__"shungeng",
         "east":__DIR__"lake"
               ]));
    set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",80);
	set("coor/z",0);
	setup();
    replace_program(ROOM);

}

