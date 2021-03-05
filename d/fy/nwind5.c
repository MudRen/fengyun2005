#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIY"神武门"NOR);
    set("long", @LONG
神武门，又称玄武门，是紫禁城北垣门，与午门同在紫禁城的中轴线上，城
墙同高约三丈，楼内设钟鼓，黄昏后鸣钟一百零八声，而后起更，打更击鼓，至
次日拂晓再鸣钟；但是皇帝居住在宫中时，神武门楼上不鸣钟。与神武门相对的
是通往御花园及东西六宫的顺贞门。选秀女时，备选的女子均由此门进出。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"southwest" : __DIR__"huantian2",
	"north" : __DIR__"ngate",
	"southeast" : __DIR__"huantian4",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",280);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    replace_program(ROOM);
}
