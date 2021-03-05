
inherit ROOM;

void create()
{
        set("short", "迷茫风雨路");
        set("long", @LONG
山势在这里渐渐升高，雾气越来越浓厚，周围的景象在浓雾中若隐若现。浓雾
中的水气穿透了你的衣裳，你的心也像被冰冷的雾气包围了。这…到底是通往天堂
的艰险之途，还是通往地狱的不归之路？
LONG
        );
        set("exits", ([ 
  		"eastup" : __DIR__"palace_path3",
  		"west" : __DIR__"palace_path1",
]));
        set("outdoors", "palace");

	set("coor/x",110);
	set("coor/y",0);
	set("coor/z",0);

	setup();
}


