inherit ROOM;
void create()
{
        set("short", "鹦鹉阁");
        set("long", @LONG
十年一觉扬州梦，赢得青楼薄幸名，有男人，有需要，就有用青春来换取财富
的地方。丽红院也好，畅春阁也罢，都和这鹦鹉楼一样，唱的，喝的，打情骂俏的，
堆着笑的老鸨，堆着脂粉的姐儿，以及堆着银子的大爷们。楼下的大厅里摆着花酒，
楼上莺花笑语，是销魂的温柔乡。
LONG
        );
        set("exits", ([ 
		"east": __DIR__"yard",
		"up":	__DIR__"redhouse0",
	]));
        set("item_desc", ([
	
	 ]));
        set("objects", ([
        	__DIR__"npc/piaoke": 1,
        ]));
	set("coor/x",-80);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	set("map","taiping");
	setup();
}
