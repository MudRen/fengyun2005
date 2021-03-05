#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "商人居");
        set("long", @LONG
小街两侧是一排平房，西北最普通，最常见的砖土四合院，住在这里的大多数
是靠手艺吃饭的，有开小杂货铺的，理发的，打铁的，伐木的。或者就像这间的主
人，常年奔波于塞外和中原做生意，最终女人耐不住寂寞改嫁了，除了逢年过节探
亲的时候，屋子就一直空关着，墙上用炭粉歪歪扭扭写了几行字。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"mroad45",
	]));
        set("item_desc", ([
		"墙":	"墙上用炭粉歪歪扭扭写了几行字“重利轻离别，我好悔也！”\n",
		"wall":	"墙上用炭粉歪歪扭扭写了几行字“重利轻离别，我好悔也！”\n",      	        
	]));
	set("objects", ([
		  
	]));
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
