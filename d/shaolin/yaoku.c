// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "药库");
        set("long", @LONG
少林寺内，能人众多，当今方丈更妙参天理，琴棋书画，配药沏茶无不精通，
更兼少室山中，名贵药材众多，所以药库之中的药皆是药中上品，有起死回生之效。
其中尤以大小还丹，三宝散，回天散为少林之宝。天下武学之士无不梦寐以求。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"bingeast",
]));
        set("objects", ([
                __DIR__"obj/keedrug" : 2,
		__DIR__"obj/keedrug2" : 1,
		__DIR__"obj/dan" : 1,
       ]) );
	set("coor/x",20);
	set("coor/y",80);
	set("coor/z",20);
	setup();

}
