
inherit ROOM;

void create()
{
        set("short", "阿龙铁匠铺");
        set("long", @LONG
寒茫的冰雪之地上，赤色的炉火烧得正旺，热气与水雾在小屋中交织，一个满
身肌肉虬然的大汉正挥汗如雨地运着火烫的大锤，一下一下铿然有声地砸着面前的
铁块，身边的冰桶中浸着数把打好的冰刃。
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"downtown",
]));
        set("objects", ([
		__DIR__"npc/alone":1,
						]) );


	set("coor/x",-50);
	set("coor/y",30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

