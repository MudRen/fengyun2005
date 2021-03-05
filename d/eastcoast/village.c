inherit ROOM;
void create()
{
        set("short", "渔村");
        set("long", @LONG
前面是个渔村，十数户人家，大部分是草屋，屋前晒着渔网，挂着风干的鱼片。
男人们都下海打鱼去了，妇人们穿着破旧但整洁的衣服在村口说笑，时不时抬头看
看归来的渔船。海面上依然迷雾一片，微微泛着波浪。碧蓝海水上涌动洁白的浪花。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"seaside1",
		"east" : __DIR__"cape",
		"west": __DIR__"village2",
	]));
        set("outdoors", "tieflag");
	set("item_desc", ([
	 ]));
	set("coor/x",1000);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

