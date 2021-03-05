inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIW"西风道"NOR);
    set("long", @LONG
风云城西最显贵的便是金钱帮的总舵，近年来金钱帮不仅迅速崛起为武林中第
一大帮，在商会，赌行，青楼各业均有涉猎，日收万金，富甲天下，帮主上官金虹
雄踞风云城，已隐隐有面南背北之势。就连当今的皇上对此也无可奈何，反倒把上
官数次召入宫中封赏笼络。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west"  : __DIR__"wcloud5",
	"east"  : __DIR__"wcloud3",
      ]));

    set("objects", ([
	__DIR__"npc/beggar" : 3,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",-240);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
