inherit ROOM;
void create()
{
        set("short", "乱草地");
        set("long", @LONG
荷塘边是一大片乱草地，日久无人照料，已有一尺多高。夜里一刮起风来，蒿
草就刷拉刷拉地响着，因为满院子都是蒿草，所以那响声就特别大，成群结队的就
响起来了。下着毛毛雨，那蒿草上就迷漫得朦朦胧胧的。
LONG
        );
        set("exits", ([ 
		"south": __DIR__"pond",
	]));
        set("outdoors", "taiping");
        set("no_fly",1);
	set("item_desc", ([  
		"蒿草": "蒿草长的又高又密，若是伏下身去，路过的人万万发现不了。\n",
		"grass": "蒿草长的又高又密，若是伏下身去，路过的人万万发现不了。\n",
	]));
	set("coor/x",60);
	set("coor/y",-70);
	set("coor/z",0);
	set("map","taiping");
	setup();
	
}
