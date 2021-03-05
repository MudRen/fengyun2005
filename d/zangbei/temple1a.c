inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "舍利塔");
        set("long", @LONG
传说，高僧却杰贡觉加错为终身供奉神山，宏扬佛法在此修建寺庙，因动土挖
石而触怒神灵，穴祸降临四周百姓，麻疯病流行。却杰贡觉加错终日念经育佛，施
展法力，乞求神灵降灾于自己，免除百姓之灾。他的慈悲举动感动了神灵，百姓平
安，他则身患疯病圆寂。现在，却杰贡觉加错的灵骨还葬在他自己建造的寺院内，
寺院僧人每日薰香念经，纪念他的大功大德。
LONG
        );
        set("exits", ([ 
		"southwest":	__DIR__"temple1",
	]));
        set("objects", ([
	]) );
	set("coor/x",-1700);
        set("coor/y",660);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
