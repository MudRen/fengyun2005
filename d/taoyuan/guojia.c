inherit __DIR__"no_killing_place";
void create()
{
	set("short", "郭宅");
	set("long", @LONG
眼前的农舍极为简单，土坯围成的墙因为年代久远已经有些剥落，茅草毡成的
屋顶年久失修，朱漆的门框已不复原色，两边的对联也已不可辨认，隐约可辨的只
有门框上的“郭宅”两字。门口的两个小石鼓倒是完整无缺。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
   		"east" : __DIR__"nongjia1",
   		"west" : __DIR__"guojia1",
   	]) );

	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",5);
	set("coor/y",20);
	set("coor/z",0);
	setup();
	replace_program( __DIR__"no_killing_place");
}
																				
																	
