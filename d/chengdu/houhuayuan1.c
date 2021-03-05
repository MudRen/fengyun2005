// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "后花园");
        set("long", @LONG
这里是火器营的后花园，周围遍栽桃、梨、柿树，搜集牡丹、芍药稀有
品种和各种奇花异草种于园内，花开时节，车水马龙，高朋满座，繁盛一时。
LONG
        );
	set("exits",([
  		"east" : __DIR__"houhuayuan2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}