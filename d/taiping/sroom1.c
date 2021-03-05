inherit ROOM;
void create()
{
        set("short", "东厢房");
        set("long", @LONG
紧接着天井是一排平房，都一律是瓦盖，房脊上还有透窿的用瓦做的花，月光
下投下长长的阴影。房脊的两梢上，一边有一个鸽子，大概也是瓦做的。终年不动，
停在那里。瓦房的窗格棂又窄又密，屋子里黑古隆冬的。
LONG
        );
        set("exits", ([ 
		"west": __DIR__"yuanzi",
	]));
	set("item_desc", ([  
	]));
	set("objects", ([
        	__DIR__"npc/whiteman": 1,
        	__DIR__"npc/whitewoman": 1,
    	]) );
	set("coor/x",90);
	set("coor/y",-80);
	set("coor/z",0);
	set("map","taiping");
	setup();

}
