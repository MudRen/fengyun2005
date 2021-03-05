inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

string pai();

void create()

{
        set("short", "林间小屋");
        set("long", @LONG
树林深处隐藏着一间小木屋，若不是有人指引，很难找到这里来。屋子里很简
朴，很干净，雪白的墙上，挂着一幅人像。画得并不好的人像，却很传神：一个白
面微须、目光炯炯有神的中年人，微微仰着脸，站在一片柳林外，身子笔挺，就像
是一杆标枪一般。人像前还摆着香案和白木的灵牌。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"woods3",
	]));
        set("objects", ([
        	__DIR__"npc/zhaodafang":	1,
        	__DIR__"npc/yidajing":	1,
        	__DIR__"obj/table":	1,
	]) );
	set("item_desc", ([
		"picture": "一个白面微须的中年人，穿的是一件紫缎锦袍，腰畔的丝带上，挂着一柄
刀，漆黑的刀！\n",
		"人像":  "一个白面微须的中年人，穿的是一件紫缎锦袍，腰畔的丝带上，挂着一柄
刀，漆黑的刀！\n",
		"白木的灵牌":	(: pai() :),
		"pai":		(: pai() :),
	]));
	
        set("coor/x",-1620);
        set("coor/y",660);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	create_door("north","door","木门","south",DOOR_CLOSED);
	
}


string pai(){

    return
    "\n"
 "		**********\n"
 "		*        *\n"
 "		*   恩   *\n"
 "		*   公   *\n"
 "		*   白   *\n"
 "		*   大   *\n"
 "		*   侠   *\n"
 "		*        *\n"
 "		*        *\n"
 "		*        *\n"
 "		*   之   *\n"
 "		*   位   *\n"
 "		*        *\n"
 "		*        *\n"
 "		**********\n";
    "\n";
}
