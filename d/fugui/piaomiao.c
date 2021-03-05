inherit ROOM;

void create()
{
	set("short", "破菩萨庙");

	set("long", @LONG
这是间破菩萨庙，年久失修，已破败不堪，山门腐朽，神像毁破，半边斜倒，
到处可见蛛网灰尘。其实这庙香火原先倒也颇旺。可是自从不远的乱葬冈开始闹鬼
后，一般百姓都没胆子敢再来了。
LONG);
	set("outdoors", "fugui");
	set("type","street");
	set("exits",([
		"southeast":__DIR__"shanlu6",
	]) );

	set("objects", ([
        	__DIR__"npc/guo" : 1,
//            "/obj/specials/ding/ding_fg" : 1,
        ]) );
	set("coor/x",-50);
	set("coor/y",140);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
