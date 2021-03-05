//Sinny@fengyun 2003
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "三仙碑");
    set("long", @LONG
白云岛本为云瘴缭绕之地，故有白云一称，后来有僧道儒三人历寒暑数十载，踏
遍中原寻觅药草，方化此毒瘴，而三人也先后故化，为了纪念三人，白云城中心建立
了一块石碑，上书：三仙聚。后来岛人在此搭建了凉台，水泉，四周繁花绿树，沁人
心脾。岛中众弟子也常喜在此小坐。
LONG
    );
    set("exits",
      ([
	"north" : __DIR__"skystreet",
	"west" : __DIR__"skystreet3",
	"east" : __DIR__"skystreet4",
	"south" : __DIR__"skystreet2",
      ]));
    set("objects",
      ([
	__DIR__"npc/byyouke" : 3,
      ]));
    set("resource/water",1);
    set("liquid",([
	"name":"三仙泉水",
	"container":"三仙泉"]));

    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-160);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
