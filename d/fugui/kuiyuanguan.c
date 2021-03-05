inherit ROOM;

void create()
{
	set("short", "奎元馆");

	set("long", @LONG
吉祥镇向来流传着这么句歌谣“麦老广的烧鸭，奎元馆的老酒”。的确，在这
么个小镇上如果还称得上特产的话，就数这两处了，奎元馆不大，地方也很挤，但
来来往往买酒喝的人还真不少，店门口那个“太白遗风”的酒旗迎风飘扬。店里的老
板娘还颇有几分姿色，上上下下忙着打点客人。
LONG);

	set("type","house");
	set("exits",([
		"west":__DIR__"xiaojie2",
	]) );

	set("objects",([
		__DIR__"npc/huoji" : 1,
	]));
	set("coor/x",30);
	set("coor/y",100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
