inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "杂货铺");
        set("long", @LONG
杂货铺的老板，是个很乐观的中年人，圆圆的脸，无论看到谁都是笑眯眯的。
别人要少忖几文钱，多抓两把豆子，他也总是笑眯眯他说：“好吧，马马虎虎算了，
反正都是街坊邻居嘛。”他姓李，别人都叫他李马虎。这时候杂货铺里少有人会来
光顾，李马虎又和平时一样，伏在柜台上打瞌睡。
LONG
        );
        set("exits", ([ 
	"east" : __DIR__"sstreet3",
	]));
        set("objects", ([
        	__DIR__"npc/limahu":	1,
	]) );
	set("coor/x",-20);
        set("coor/y",-30);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
