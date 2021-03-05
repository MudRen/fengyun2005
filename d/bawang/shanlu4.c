inherit ROOM;

void create()
{
    set("short", "饿虎寨");

	set("long", @LONG
渐渐地，你已经接近饿虎岗的核心地带：聚义厅。时不时可见各色土匪毫强在
路边游荡，大块吃肉，大口喝酒。或者掷骰子赌钱。生活得倒也逍遥自在。南边通
往聚义厅的路上有一座寨门，但是现在紧锁着，而且戒备森严，不能随便出入。
LONG);

	set("type","road");
	set("outdoors", "bawang");
	set("exits",([
		"northdown":__DIR__"shanlu3",
	]) );
	set("objects", ([
		__DIR__"npc/yue_lin":1,
		__DIR__"npc/chen_zhun": 1,
		__DIR__"npc/yi_hu": 1,
		__DIR__"npc/female_bandit": 2,
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
