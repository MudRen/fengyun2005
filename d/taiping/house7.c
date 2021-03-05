#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "剃头店");
        set("long", @LONG
孙剃头年轻的时候挑着剃头担子走南闯北，着实经历过一番市面，最得意的就
是曾被叫到金钱帮里使唤过半年，从而有机会远远见到了上官金虹和李寻欢在长亭
里相约的一幕。孙剃头渐渐老了，糊里糊涂出了几次差错，所以就回到了太平镇，
开了个小店糊口，心情好时就给乡亲们讲讲中原的见闻。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"mroad7",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("objects", ([
	        __DIR__"npc/barber": 1,
	]));
	set("coor/x",-30);
	set("coor/y",-70);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

/*
红巷靠南的一侧是一排平房，西北最普通，最常见的砖土四合院，住在这里的
大多数是靠手艺吃饭的，有开小杂货铺的，理发的，打铁的，伐木的，也有的是常
年奔波于塞外和中原的生意人。
*/
