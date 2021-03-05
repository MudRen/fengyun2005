inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"南云街"NOR);
    set("long", @LONG
街道西边的普生堂远近驰名，听说当年皇上游览风云城时被刺，身受重伤，幸
亏是普生的灵丹妙药才令皇上起死回生，堂中的金匾就是御赐的。普生堂对面新开
了一家神农居，老板据说乃是经年在五岳大山大川中采集草药的一代神医百里零，
由于他常年在外，所以神农居现在由其侄女百里雪打理日常买卖。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"swind4",
	"north" : __DIR__"swind32",
	"east" : __DIR__"shennong",
	"west" : __DIR__"pusheng",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-240);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}
