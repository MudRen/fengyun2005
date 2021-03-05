#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIY"金钱门"NOR);
    set("long", 
"这里没有任何别的东西，只有一扇门，厚厚的金漆铜门敞开着，门前却没有一
个护卫；这里就是金钱帮的总舵，百晓生兵器谱上排名第二的“龙凤双环”上官金虹
一手创立的天下第一帮；在这里的确也不需要任何侍卫，因为从来没有人敢在这里放
肆，即使有，也只是死人。门前高高悬着一块金匾，上书："
+HIY"

                      金    钱    帮

"NOR        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wcloud3",
  "north" : __DIR__"jinqian",
]));
        set("outdoors", "fengyun");
        set("objects", ([
                        ]) );

 set("coor/x",-160);
set("coor/y",40);
	set("coor/z",0);
set("map","fywest");
	setup();
//	replace_program(ROOM);
}

