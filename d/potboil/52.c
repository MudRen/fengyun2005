#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"安儿的巴山大药房"NOR);
	set("long", @LONG
一进这屋，墙角支着的一团大红的颜色就引去了你的目光，定睛看去，原来是
系在一面旗幡之上的大葫芦，用来充作招牌的物事。只是那葫芦和寻常走方郎中幡
子上的葫芦有所不同，通体用朱漆刷了，远远望去俨然一块朱砂仿佛。再看那面旗
幡，却是最为平常不过的粗布，灰不溜秋毫不起眼。上书八个大字＂仙手仁术，济
世为怀＂其字迹潦草，着墨粗劣，全无章法可言。
LONG
        );
	set("exits",([
		"westdown" : __DIR__"42",
	]) );

/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/

  	set("coor/x",50);
	set("coor/y",20);
	set("coor/z",-10);
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
