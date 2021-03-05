inherit ROOM;

void create()
{
	set("short", "山下小径");
	set("long", @LONG
一条蜿蜒的泥土小径，两旁疯长着些野草野花。拂面的山风中散发着阵阵血腥
气味。山雾也越来越大，白茫茫的一片几乎看不清上山的路，隐约间可看见西南方
向不远处有一座断塔。
LONG);

	set("type","road");
	set("exits",([
        "northwest":"/d/wudang/xzroad4",
        "southup":__DIR__"shanlu2",

	]) );
	set("outdoors", "bawang");
	set("coor/x",0);
	set("coor/y",70);
	set("coor/z",-70);
	setup();
	replace_program(ROOM);
}
