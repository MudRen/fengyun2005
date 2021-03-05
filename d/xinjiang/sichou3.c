inherit ROOM;
void create()
{
        set("short", "交河故城");
        set("long", @LONG
此城位于雅尔乃孜沟中，系古西域三十六国“车师前国”的故城，该城建在自
北向南高十多丈的黄土台地上，岸崖笔立如削，壁垒天然。交河城仅有东门和南门
两座城门。由于城建在县崖上，不用筑城墙，城门亦非正式建筑，南门是运送粮草、
大军出入的主要通道，有“一人守隘，万夫莫向”的山口。东门巍然屹立在的峭壁
上，是为城内居民汲引河水的门户。
LONG
        );
        set("exits", ([ 
  		"northwest" : __DIR__"sichou2",
  		"eastdown" : __DIR__"tulufan",
]));
        set("objects", ([
        	__DIR__"npc/bird" : 2,
                        ]) );
        //set("no_pk",1);
         
        set("outdoors", "xinjiang");
	set("coor/x",50);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
