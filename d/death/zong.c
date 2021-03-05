// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "冥府忠司");
        set("long", @LONG
进得忠司，便见当面一金盔银甲的将军端坐椅上，两侧数位纶巾文士，长须飘
飘，仙风道骨。
LONG
        );
        set("exits", ([
		"southeast" : __DIR__"naihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/yuefei":1,
        ]) );
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
 
