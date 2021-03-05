#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"阆风庭"NOR);
	set("long", @LONG
阆风又名高丘，意指昆仑。海内十州记所载，昆仑山三角，一角正干北辰
，即名阆风：阆风庭有玉楼十二，立台九层，乃历朝历代神教长老会诸众的静
修之地。
LONG
        );
	set("exits",([
		"northdown" : __DIR__"46",


	]) );

	set("objects", ([
	__DIR__"npc/bu" : 1,
					]) );

  	set("coor/x",40);
	set("coor/y",50);
	set("coor/z",10);
	set("outdoors", "potboil");
	setup();
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
