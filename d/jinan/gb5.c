// Tie@fy3
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "草棚");
  set("long",@LONG
舜耕山庄旁边的一个暗角，一个一般人都不愿走近的地方；一个简陋得无可再
简陋的草棚，一阵阵扑鼻的肉香便是从这里传出来。每到傍晚总会有几个穿得破旧
不堪的乞丐围着烧得熊熊的火锅边放口大嚼。
LONG
  );
  	set("exits",([
        	 "east":__DIR__"shungeng",
               ]));
    	set("outdoors", "jinan");
        set("coor/x",-30);
        set("coor/y",80);
        set("coor/z",0);
	setup();
}