#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"午门"NOR);
    set("long", @LONG
由午门北行，便是巍峨的紫禁皇城了，门分五洞，正中为当今天子的御道，文
武百官走左门进出，宗室王公从右门进出，一般官员只能经两侧掖门进出，等级森
严，不得违犯。唯一的例外是，当经殿试考中新科状元、榜眼、探花者，在发黄榜
这天，可从正门出宫一次。城门高大巍峨，约数十丈许。城门有武士守卫。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"nwind1",
	"north" : __DIR__"nwind3",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",120);
    set("coor/z",0);
    set("map","fynorth");
    setup();

}
