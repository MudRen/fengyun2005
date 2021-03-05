#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"冰雪州"NOR);
	set("long", @LONG
传闻魔教第四代大司律原本是凌人出身，擅于弄冰之术；因有极惧苦炎的
怪癖，教主特许他搬出青云栈、在此处以千年不化之冰雪另立新居，此后每一
位大司律均居住在此，亦尽皆秉承覆积冰雪而眠的古风。
LONG
        );
	set("exits",([
		"eastdown" : __DIR__"65",
	]) );

	set("objects", ([	// * WATER RESOURCE HERE.
	__DIR__"npc/qu" : 1,
					]) );

  	set("coor/x",50);
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
