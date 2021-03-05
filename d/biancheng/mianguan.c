inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "面馆");
        set("long", @LONG
面馆的老板是张老实。张老实真的是个老实人，他不但是这小面馆的老板，也
是厨子和伙计，所以一年到头，身上总是围着块油腻腻的围裙，从早上一直忙到大
黑，赚来的钱却连个老婆都养不起。但他还是整天笑嘻嘻的，你就算只去吃他一碗
三文钱的阳春面，他还是拿你当财神爷一样照顾。所以他煮的面就算像浆糊，也从
来没有人埋怨半句。
LONG
        );
        set("exits", ([ 
	"east" : __DIR__"sstreet1",
	]));
        set("objects", ([
        	__DIR__"npc/bosszhang":	1,
	]) );
        set("coor/x",-20);
        set("coor/y",-10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	
}

void reset(){
	if (present("pan ling",this_object()))	return;
	::reset();
}	