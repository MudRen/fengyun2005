inherit ROOM;
void create()
{
        set("short", "天井");
        set("long", @LONG
花园东侧有一道月洞门，门后是一个天井，两侧是佣人住的侧房。天井不大，
十数丈见方，青石地面上面还有些晾衣晒谷的残余。朝雾从环山吹来，整个庄院
都在雾中，天井中同样淡雾迷离。
LONG
        );
        set("exits", ([ 
		"west": __DIR__"lroad1",
		"east": __DIR__"sroom1",
		"south": __DIR__"sroom2",

	]));
        set("outdoors", "taiping");
	set("item_desc", ([  
	]));
	set("coor/x",80);
	set("coor/y",-80);
	set("coor/z",0);
	set("map","taiping");
	setup();

}
