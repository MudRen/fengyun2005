// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "千佛殿");
        set("long", @LONG
又名昆卢阁，雕饰相当精致，明间悬额有“西方圣人”的竖匾，殿前月台宽敞，
石栏精美。殿正中的神龛里，供奉昆卢铜佛，坐于多层莲花座上，殿东有白玉南无
阿弥陀佛一尊，四周壁画精美，尤其引人注目的是地上的四十八个凹陷的[33m脚坑[32m。
LONG
        );
        set("exits", ([ 
  "northdown" : __DIR__"neimen",
  "southdown" : __DIR__"lishi",
  "east" : __DIR__"baiyi",
  "west" : __DIR__"dizang",
]));
        set("objects", ([
                BOOKS"dodge_50" : 1,
       ]) );
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",20);
	setup();

}
