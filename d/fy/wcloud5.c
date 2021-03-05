
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIW"西门东"NOR);
    set("long", @LONG
愈近西城口，街道越发宽阔，行人却愈渐减少，路边更少店家，唯有几幢不起
眼的红房，是城里守军的行营。风过，尘沙漫天，不时有马车滚滚驶向城外，而驾
马疾驰的江湖人也行色匆匆，无暇顾及两旁。向前看，高大的西城墙已远远在望，
映着背后起伏的山峦，如猛虎般雄踞。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"barracks2",
	"west"  : __DIR__"wgate",
	"east"  : __DIR__"wcloud4",
      ]));

    set("outdoors", "fengyun");
    set("coor/x",-280);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
