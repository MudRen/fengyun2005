// Reference point, (-900, 2500, 0)
inherit ROOM;
#include <ansi.h>


void create()

{
        set("short", "阳关古址");
        set("long", @LONG
阳关故址位于玉门关西北，古以南为阳，故称“阳关”，是中原与西域陆路交
通咽喉之地，也是“丝绸之路”南路必经的关隘。古城关东面为农田，远处有寿昌
城废址，三面沙丘，沙梁环抱，流沙茫茫，一望无际。南面墩墩山上有一汉代烽燧，
北有南北走向的深沟，沟中泉水涓涓，甚为甘冽。
LONG
        );
        set("exits", ([ 
	"northwest" : __DIR__"yangguan1",
	"east" : AREA_QUICKSAND"yangguan",
	"north" : __DIR__"oasis",
	]));
        set("objects", ([

	]) );
	set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	replace_program(ROOM);
}
