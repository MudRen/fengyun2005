inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"南云街"NOR);
    set("long", @LONG
街道就象水洗过那么的干净，汉白玉砌的路面光明如镜，两侧的瓦房高大宏伟，
双人合抱的杨树十步一株，整齐的排在两边。大街西面是一间珠光宝气的小阁，小
巧精致，便是玉龙珠宝店了。大街东面宅上有一西式风格的建筑，宅顶竖着高高的
十字架，一些金发碧眼，身披黑袍的人不时出出入入。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"swind3",
	"north" : __DIR__"yundoor",
	"east" : __DIR__"church",
	"west" : __DIR__"yuljade",
      ]));
    set("objects", ([
	__DIR__"npc/dtz1" : 2,
//	__DIR__"npc/patrol_soldier": 1,
      ]) );
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-80);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}
