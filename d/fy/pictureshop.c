#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "山水阁");
    set("long", @LONG
这一间画院规模并不甚大，院中摆设也极为普通，三两竹椅，但一进得这里，
左顾仿佛置身名山大川，右看似乎徜徉于花海石林，一个不留神，身边竟仿佛有
衣带飘飘的绝代佳人正婀娜起舞。一定神，才发觉这些幻像都只是四壁挂着的历
代名画。真可谓“鸣鸠乳燕初睡起，白波青嶂非人间”。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"swind32",
      ]));

    set("objects", ([
	__DIR__"npc/zhong": 1,
      ]) );

    set("indoors", "fengyun");
    set("coor/x",20);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}

