inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIW"西风道"NOR);
    set("long", @LONG
西风道的北侧最显贵的便是金钱帮的总舵，表面看起来却也不是如何豪华，但
江湖传言金钱帮总舵有一个庞大的地下王宫，其规模堪比皇城，帮主上官金虹雄踞
此地，已隐隐有面南背北之势。西风道南面巨宅的飞檐下一个闪亮的银钩在日光下
闪闪发光，似乎在汉白玉的路面上铺上了一层银粉，便是城中最豪华的银钩赌坊。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"jindoor",
	"south" : __DIR__"yingou",
	"west"  : __DIR__"wcloud4",
	"east"  : __DIR__"wcloud2",
      ]));

    set("outdoors", "fengyun");
    set("coor/x",-160);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
