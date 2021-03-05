#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "平安道");
        set("long", @LONG
人死后，至阎王殿去接受发判，判定后，则将生前功过录入转回册中，若是作
恶多端的，押入十八层地狱受苦，若是可转世投胎的鬼魂，则途经地狱，走过平安
道，到奈何桥去投胎。因为此地是投生的人必经之路，所以十分安静，如果稍有喧
哗，便会再呆上十年。平安道的两侧是[33m枉死城、孟婆亭[32m等去处。
LONG
        );
        set("exits", ([
		"southwest": __DIR__"nanbank",
		"southeast": __DIR__"hospital",
		"northeast": __DIR__"mengpo",
		"northwest": __DIR__"wangsi",
		"south" : __DIR__"aihe",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-190);
	set("no_fight",1);
	set("no_meal","你忽然发现口中的食物饮水成了苦涩的浊泥，赶快哇哇地吐了出来。\n");
	setup();
        
}
 
