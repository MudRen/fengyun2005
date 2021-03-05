#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIC"南云街"NOR);
    set("long", @LONG
街道就象水洗过那么的干净，汉白玉砌的路面光明如镜，两侧的瓦房高大宏伟，
双人合抱的杨树十步一株，整齐的排在两边。热闹的街道上充溢着清新的花香和甜
丝丝脂粉的香气。花香是从大街东侧的飘香花店荡漾出来的，而浓厚的脂粉气息则
是西首倾城胭脂店的招牌。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"swind32",
	"north" : __DIR__"swind3",
	"east" : __DIR__"pxhdian",
	"west" : __DIR__"qcyzdian",
      ]));


    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-160);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}

