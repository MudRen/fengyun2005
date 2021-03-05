inherit ROOM;

void create()
{
	set("short", "山间小路");

	set("long", @LONG
这是条不知通往何处的山间小路，路旁点缀着些或黄，或白，或红，或紫的
小花，煞是若人喜爱，不远处的山涧轻快的流淌着，席席的秋风送来远处小镇上
人家炊火的香气，你不禁有些饥肠辘辘，不知道何处能觅得些好吃的饭菜。路的
西北处隐隐透出间寺庙的檐角。
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"northeast":__DIR__"shanlu5",
		"northwest":__DIR__"piaomiao",
	]) );
	set("coor/x",-40);
	set("coor/y",130);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
