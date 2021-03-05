
inherit ROOM;

void create()
{
        set("short", "荒野");
        set("long", @LONG
这是一个无边的荒野地，山势到了这里突然间变的叠叠起起，连绵不断再往北
行则是去大沙漠的荒凉小路，往西北方向远远眺望则是五岳之一的[33m华山[32m界内，陡峭
的山峦直插云霄，巍峨壮丽。继续向北便是无边无际的大[33m沙漠[32m。
LONG
        );
    set("exits", ([ 
        "north" : __DIR__"roadp",
		"southup" : __DIR__"chenxiang3",
        "northwest" : AREA_HUASHAN"road1",
	]));
        set("outdoors", "chenxiang");

	set("coor/x",-10);
	set("coor/y",70);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}

