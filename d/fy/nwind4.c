#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIY"团龙石阶"NOR);
    set("long", @LONG
太和门后长达数百丈的团龙石阶直达太和金殿。石阶上团龙浮雕，张牙舞爪，
威武异常。石阶两侧排列着六只巨大的青铜巨鼎，威武踞守，君临天下。太和门两
侧，还设有昭德、贞度两座旁门。三门并列一起，主次分明，气势不凡。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"nwind3",
	"north" : __DIR__"hall",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/dtz": 2,
      ]) );
    set("coor/x",0);
    set("coor/y",200);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    replace_program(ROOM);
}

