// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "武库");
        set("long", @LONG
这是少林武库，少林自从唐以来，便因为护唐王有功，所以可以自拥僧兵，自造
武器，历代帝王更常令名铸剑师落发少林，协助打造，所以屋内琳琅满目，各色武器
防具一应俱全。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bingwest",
]));
        set("objects", ([
                "/obj/weapon/sword" : 1,
                "/obj/weapon/blade" : 1,
                "/obj/weapon/staff" : 2,
                "/obj/weapon/hammer": 1,
                "/obj/weapon/whip"  : 1,
                "/obj/weapon/axe"   : 2,
       ]) );
	set("coor/x",-20);
	set("coor/y",80);
	set("coor/z",20);
	setup();

}
