#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"千机阁"NOR);
	set("long", @LONG
千机阁打扫得很乾净，窗明几净，一尘不染，两边各有一扇小门，门上挂
着竹帘，帘外系着铃铛。阳光斜照，阵阵柔绚的微风轻袭，竹帘与风铃轻轻摇
动，叮咚作响。这里没有一丝杀气，却是魔教每一道倾覆天下的指令牵动的中
心。
LONG
        );
	set("exits",([
		"west" : __DIR__"33",
		"east" : __DIR__"53",
		"southdown" : __DIR__"42",
	]) );

	set("objects", ([
	__DIR__"npc/huo" : 1,
					]) );

  	set("coor/x",40);
	set("coor/y",30);
	set("coor/z",0);
	set("indoors", "potboil");
	setup();
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
