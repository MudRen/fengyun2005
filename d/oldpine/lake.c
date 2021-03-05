// Room: /d/oldpine/lake.c

inherit ROOM;

void create()
{
        set("short", "水潭");
        set("long", @LONG
你现在正站在一个深不见底的水潭边上，从潭底不时有气泡冒上来，散发著一
股诡异的香味，水潭边长满了[37m黄色叶子[32m的怪草，四周陡峭的山壁近乎直立，抬头只
见一个半圆形的天空，唯一的出路大概只有往北山泉流入水潭的缺口。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  			"north" : __DIR__"riverbank1",
		]));
		
        set("item_desc", ([
        	"黄色叶子": 	"水潭边长满了黄色的叶子，故名黄叶潭。\n",
        ]));
               
        set("objects", ([ /* sizeof() == 1 */
  			__DIR__"npc/serpent" : 1,
		]));
        set("resource/water", 1);
        set("liquid/name", "黄叶潭水");
		set("coor/x",0);
		set("coor/y",-10);
		set("coor/z",0);
		setup();
        replace_program(ROOM);
}
