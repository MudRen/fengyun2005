// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "武侯祠大院");
        set("long", @LONG
大门匾额为“汉昭烈庙”。大门内浓荫丛中，矗立着六通石碑，两侧各有一碑廊，
碑文对诸葛亮的一生，作了重点褒评；竭力赞颂诸葛亮的高风亮节，文治武功，碑文
通篇辞句甚切，文笔酣畅，使人百读不厌。
LONG
        );
	set("exits",([
  		"north" : __DIR__"wuhouci3",
  		"south" : __DIR__"wuhouci1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}