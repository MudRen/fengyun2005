inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "节妇坊");
        set("long", @LONG
节妇坊是个很高的贞节牌坊，在阳光下看来，就像是白玉雕成的。牌坊两旁，
是些高高低低的小楼，窗子都是开着的，每个窗口都挤满了人头。他们正看着这贞
节牌坊前站着的二十九个人。二十九个身穿白麻衣、头上扎着白麻的人。这些人有
男有女，有老有少，每个人手里，都倒提着柄雪亮的鬼头大刀。每个人脸上，都带
着种无法形容的悲壮之色，就像是一群即将到战场上去和敌人拼命的勇士。
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"road6",
	]));
        set("objects", ([
        	__DIR__"npc/guowei":	1,
        	__DIR__"npc/guobaobao":	1,
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-50);
        set("coor/y",10);
        set("coor/z",0);
        set("no_lu_letter",1);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
