inherit ROOM;
void create()
{
        set("short", "后院");
        set("long", @LONG
后面的院子非常阴森。没有灯，只有天边的一弯新月斜照下暗淡的光芒。没有
灯的地方本来就已阴森的了，何况这院子当中还植着一株白杨。白杨蒂长叶大，风
一吹就沙沙作响，是秋树中最令人萧瑟一种，亦是萧瑟秋声的代表。院子里的西风
此际正急。白杨多悲风，萧萧愁煞人。在这个院子，这个时候，又岂只愁煞人，简
直已吓煞人。
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"house3",
		"south":__DIR__"house3c",
	]));
	set("objects", ([
        ]) );

        set("item_desc", ([
		"白杨":	"院子里的西风此际正急，白杨树叶瑟瑟作响。\n",	
		"tree":	"院子里的西风此际正急，白杨树叶瑟瑟作响。\n",
	 ]));
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
