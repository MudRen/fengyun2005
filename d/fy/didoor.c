#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",HIG "地坛"NOR);
    set("long", 
"天机广场往东便是风云城中三教九流汇聚的东城区，紧靠着广场为地坛，乃风
云百姓祭祀天地之所，坛内收藏神版牌位，每逢祭祀前一天才将五岳、五镇、四海、
四渎等牌位舁于祭台上。坛上终日香火缭绕，云蒸霞蔚，坛南连有一所城隍古庙，
据传已有五百多年的历史。地坛中央上书："+HIG"

                      地           坛
                  
"NOR
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"ecloud1",
  		"south" : __DIR__"hiretem",
  		"west" : __DIR__"fysquare",
	]));
        set("outdoors", "fengyun");
 set("coor/x",40);
 set("coor/y",0);
	set("coor/z",0);
 set("map","fyeast");
	setup();

}
