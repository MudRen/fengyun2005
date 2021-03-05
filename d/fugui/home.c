inherit ROOM;

void create()
{
	set("short", "民居");

	set("long", @LONG
这是一家泥砌的房屋，家徒四壁，屋角的米缸是空的，连厨房内的水缸也是空
的。几个缺胳膊少腿的桌椅靠墙立着。看来主人已经把所有能值钱的东西全都变卖
了。
LONG);

	set("type","house");
	set("exits",([
	"west":__DIR__"xiaojie1",
	]) );

	set("objects",([
		__DIR__"npc/oldman":1,
	]));
	set("coor/x",30);
	set("coor/y",110);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
