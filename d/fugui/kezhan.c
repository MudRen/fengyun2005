inherit ROOM;

void create()
{
	set("short", "如意客栈");

	set("long", @LONG
这里便是镇上最大的一家客栈了，叫做“如意客栈”，取的是吉祥如意的彩头，
店里也没什么生意，伙计正趴在小桌上打盹，老板似乎也没什么精神，拿着本帐薄
随意的翻弄着。
LONG);

	set("type","house");
	set("exits",([
		"east":__DIR__"xiaojie1",
		"west":__DIR__"kf2",
		"up":__DIR__"kefang",
	]) );
	
	set("objects",([
		__DIR__"npc/laoban" : 1,
	]));
	set("coor/x",10);
	set("coor/y",110);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
