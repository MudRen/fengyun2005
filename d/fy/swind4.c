inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"南门北"NOR);
    set("long", @LONG
再往南行，便是出风云城的南门了。东西两侧是热闹的环云道，虽说出入这里
的大都是一些血气方刚，默默无名的江湖新血，但又有谁能怀疑，就在这些看上去
愣头愣脑的小伙，风风火火的丫头里没有将来叱咤风云的一代天骄？
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"sgate",
	"north" : __DIR__"swind5",
	"east" : __DIR__"huanyun10",
	"west" : __DIR__"huanyun23",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-280);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}
