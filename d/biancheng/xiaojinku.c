inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "销金窟");
        set("long", @LONG
街上最窄的一扇门，这里的销金窟。门虽最窄，屋子占的地方却最大。窄门上
既没有招牌，也没有标志，只悬着一盏粉红色的灯。灯亮的时候，就表示这地方已
开始营业，开始准备收你囊里的钱了。灯熄着的时候，这门里几乎从未看到有人出
来，当然也没有人进去。这里竟像是镇上最安静的地方。
LONG
        );
        set("exits", ([ 
	"north": __DIR__"road5",
	"south": __DIR__"xiaojinku2",
	]));
        set("objects", ([
	]) );
        set("coor/x",-40);
        set("coor/y",-10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	create_door("south","door","窄门","north",DOOR_CLOSED);
}
