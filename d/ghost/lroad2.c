
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
城门南面是一条弯曲的泥土路。路边杂草丛生，没有住家，路上泥泞不堪，车
马难行。再往前走就进入了一片原始森林，黑压压的无边无际，说从来没人能走出
过那里。当地人把它叫做“格木达纳巴”，意思就是幽灵鬼怪出没的地方。
LONG
	);
	set("exits", ([
                "north" : __DIR__"lroad1",
                "south" : __DIR__"lroad3",
	]));
	set("coor/x",-90);
	set("coor/y",60);
	set("coor/z",10);
	setup();
replace_program(ROOM);

}
