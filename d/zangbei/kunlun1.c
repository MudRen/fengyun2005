inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "和阗河");
        set("long", @LONG
穿过沙漠，便到了塞北之地。和阗河滚滚的河水，在六月的残阳下发着光。到
了上游，河水双分，西面的一支便是玉龙哈什河，水流处地势更见崎岖险峻，激起
了奔腾的浪花。和阗河的南侧是[33m太平镇[32m，原先只是个驿站，歇脚的人多了，渐渐就
开起了几家店铺。河北侧通向[33m嵩岳寺[32m，人烟罕至，多有山贼出没。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"kunlun2",
		"southeast" : __DIR__"yangguan2",
		"southwest": AREA_TAIPING"mroad1",
		"north":	__DIR__"qingtongxia",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",-500);
        set("coor/y",500);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	replace_program(ROOM);
}
