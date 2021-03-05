inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIW"西风道"NOR);
    set("long", @LONG
西城是当今江湖第一大势力金钱帮总舵所在，上官金虹苦心经营数年，原本寥
落破败的地面上建起了片片豪宅，与北区的紫禁城竟有日月争辉之势。街道两侧珠
光宝气，银庄钱楼，人来人往，热闹异常，南侧更有一家“眼波横”戏楼，自打年
前请到江南两大名旦，已成为风云城内一大胜景。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"theater",
	"west"  : __DIR__"wcloud2",
	"east"  : __DIR__"fengdoor",
	"north":  __DIR__"adventure",
      ]));
    set("objects", ([
	__DIR__"npc/song": 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",-80);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);   //add by ldb 

}
