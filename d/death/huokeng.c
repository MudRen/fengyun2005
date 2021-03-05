// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "火坑狱");
        set("long", @LONG
一进来，扑面的热气几乎让你昏了过去，火海之中，几个犯人正在来回穿梭，
每过一次，浑身骨肉俱成焦炭，然后被鬼卒浇上神水后恢复原样，又拿着铁棒赶进
火里。你不由得心胆俱焚，暗自庆幸生前未曾做下什么罪业。由此向下是酆都狱。
LONG
        );
        set("exits", ([
		"up" : __DIR__"yiuwang",
		"down" : __DIR__"yandu",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-30);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
