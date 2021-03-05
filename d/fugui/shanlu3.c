inherit ROOM;

void create()
{
	set("short", "山间小路");

	set("long", @LONG
这是条不知通往何处的山间小路，路旁点缀着些或黄，或白，或红，或紫的
小花，煞是若人喜爱，不远处的[37m山涧[32m轻快的流淌着，席席的秋风送来远处小镇上
人家炊火的香气，你不禁有些饥肠辘辘，不知道何处能觅得些好吃的饭菜。
LONG);

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"north":__DIR__"shanlin",
		"southeast":__DIR__"shanlu2",
		"southwest":__DIR__"shanlu4",
	]) );
	        set("objects", ([
                __DIR__"obj/flower1" : 1,
                __DIR__"obj/brook" : 1,
        ]) );
        set("resource/water",1);
		set("liquid/name","山涧水");
		set("liquid/type", "water");
		
	set("coor/x",-10);
	set("coor/y",140);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
