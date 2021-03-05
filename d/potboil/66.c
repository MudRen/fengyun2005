#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"东北角"NOR);
	set("long", @LONG
这间小阁中四面摆满了香烛、素幔，阁楼角落中四柱雕纹的宫灯正燃着幽
蓝色的光芒，木地板上用惨蓝色的不知什么画着诡谲的三角纹路，周围密密麻
麻地绘著无数血红符文，让人毛骨悚然。
LONG
        );
	set("exits",([
		"west" : __DIR__"56",
		"south" : __DIR__"65",
	]) );

	set("objects", ([
	__DIR__"npc/mei" : 1,
					]) );

  	set("coor/x",60);
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
