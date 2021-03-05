#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"西北角"NOR);
	set("long", @LONG
四壁是无以名之的颜色，字画边悬着的对联已因残旧而略有剥落，但因有
人们勤加拂拭，屋内倒也窗明几净。楼宇后是个阁楼，相当宽做，当中放了花
梨香案，文房四宝俱全。紫檀木架上间以玉石，搁着些木雕摆设，古瓷花瓶中
已无花影，座上却还有一个烛台，红烛半残直如女子洗尽了铅华。
LONG
        );
	set("exits",([
  		"east" : __DIR__"46",
		"south" : __DIR__"35",
	]) );

	set("objects", ([
	__DIR__"npc/ju" : 1,
					]) );

  	set("coor/x",30);
	set("coor/y",60);
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
