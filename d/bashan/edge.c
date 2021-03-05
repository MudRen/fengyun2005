#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "林盖边缘");
        set("long", @LONG
历尽千辛万苦，你总算离开了这片让人头晕目眩的巴山密林。向前看去，一根
半朽的老木正搭着对崖的山头黑土，漫漫路上只有及膝深草，再无一棵参天巨木。
你舒了一口长气，心中却又有些忐忑不安：越过这片看似平静的山头，前方又等待
着什么样的埋伏？
LONG
        );
	set("exits",([
//  		"down" : __DIR__"maze3/exit",
  		"north" : __DIR__"edge2",
	]) );
	set("no_fly",1);
	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",200);
	set("outdoors", "bashan");
	setup();
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
