inherit ROOM;

void create()
{
        set("short", "寝宫");
        set("long", @LONG
宽大的殿堂，处处张灯结彩，这古老的殿堂蒙上了一层鲜艳的色彩后，看来就
更是辉煌。玉石阶前，已铺起了红毡，尽头设有一座玉案，两张锦椅，这想必就是
快活王和他的王妃的位子。下面，左右两旁，各各也有一张长案，案上有四副杯筷，
自然都是金盆玉盏，极致华贵。
LONG
        );

        set("exits", ([ 
		"north" : __DIR__"eaststrt2",
	]));
        set("objects", ([
                
	]) );
        set("indoors", "loulan");

	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
