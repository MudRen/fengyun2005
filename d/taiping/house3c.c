inherit ROOM;
void create()
{
        set("short", "贮藏室");
        set("long", @LONG
这儿本来是主人囤积过冬食物的地方，常笑来此办案后，把它改成了审问犯人
和检验尸体的地方。窗外冷雾凄迷，风穿窗吹入，吹入了冷雾，整个屋子都是雾蒙
蒙的。现在只不过初秋，还是苍蝇的季节，灯火下一群苍蝇展翅飞舞，嗡嗡作响。
LONG
        );
        set("exits", ([ 
		"north": __DIR__"house3b",
	]));
	set("objects", ([
        	__DIR__"npc/tangda" : 1,
        	__DIR__"npc/liner" : 1,
        ]) );

        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
