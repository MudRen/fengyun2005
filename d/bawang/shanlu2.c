inherit ROOM;

void create()
{
    set("short", "泥土小径");

	set("long", @LONG
一条蜿蜒的泥土小径，两旁疯长着些野草野花。拂面的山风中散发着阵阵血腥
气味。山雾也越来越大，白茫茫的一片几乎看不清上山的路，隐约可见不远处有两
棵巨树的黑黝黝的影子。树下似乎有人影晃动。
LONG);

	set("type","road");
	set("exits",([
        "southup":__DIR__"ehugang",
        "northdown":__DIR__"shanlu",
	]) );
	set("outdoors", "bawang");
	set("coor/x",0);
	set("coor/y",60);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
