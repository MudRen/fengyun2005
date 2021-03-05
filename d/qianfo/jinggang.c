//mac's jinggang.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","金刚殿");
  set("long",@LONG
两尊力士执金刚杵分立左右。都是面貌雄伟，作忿怒相，头戴宝冠，上半身赤
裸，两脚张开，呈紧张状，左像怒颜张口，以杵作打物之势，右像忿颜闭口，平托
金刚杵，怒目睁视。
LONG
  );
  set("exits",([
         "south":__DIR__"chansi.c",
         "west" :__DIR__"fangsheng.c",
         "north":__DIR__"qianyuan.c",
         "east" :__DIR__"fudong.c"
               ]));
        set("objects", ([
                __DIR__"npc/lishi" : 2,
       ]) );
	set("coor/x",0);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
