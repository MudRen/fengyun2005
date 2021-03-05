// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "沉香台");
        set("long", @LONG
天气酷热，竹林茂盛，这个竹亭居然是天然形成，竹根，竹叶，和竹杆交织在
一起，真可谓鬼斧神功，镇民经常在这儿看戏聚会，把它叫做沉香台。西面的一条
街是镇上的日常购物之处，油盐杂货、胭脂首饰，无所不有。南面是官府的衙门和
一个小小的城隍庙。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs1",
  "west" : __DIR__"cxw1",
  "south" : __DIR__"cxs2",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
 

}
