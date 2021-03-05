inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "边城东门");
        set("long", @LONG
小城的一端，是无边无际的草原，小城的另一端，也是无边无际的草原。这个
[33m边原小镇[32m，仿佛就是天地间唯一的一粒明珠，一粒粘满了世俗尘灰的明珠。街道虽
不长，也不宽，却也有几十户店人家。太阳照在街上，闪着金光，小镇在早春的寒
风中喘息。
LONG
        );
        set("exits", ([ 
	"southeast" : AREA_ZANGBEI"wild7",
	"west" : __DIR__"road2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
	setup();
	replace_program(ROOM);
}
