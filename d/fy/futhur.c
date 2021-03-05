inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", "红屋");
    set("long", @LONG
这是东城区算得比较气派的建筑，但颜色很怪，一种血色干凝的暗红色。屋里
更是鬼气森森。房子无窗，一盏油灯忽明忽暗。以太极八卦图为底的招牌上用篆体
刻着四个字“生死已卜”，也是黯淡无光的红色。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"yulong31",
      ]));
    set("objects", ([
	__DIR__"npc/dashi" : 1,
      ]) );

    set("coor/x",260);
    set("coor/y",40);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
