inherit ROOM;

void create()
{
	set("short", "翠竹园");

	set("long", @LONG
“有竹无肉轩”四周就是翠竹园，这里种满了竹，每到风清月白的夏夜，富贵
山庄的历代主人们便会来此，一把竹椅，一壶清茶，听那海浪般的竹涛声，可惜王
动很久已经没这个兴致了，倒是会时常和他的兄弟们砍竹卖钱换酒，年复一年，翠
竹园中的竹子也越来越少。
LONG
	);
	set("outdoors", "fugui");
	set("type","forest");
	set("exits",([
		"east":__DIR__"wuzhuxuan",
	]) );
	set("objects",([
		__DIR__"npc/yafeng":1,
	]));
	set("coor/x",-20);
	set("coor/y",210);
	set("coor/z",80);
	setup();
	setup();
	replace_program(ROOM);
}
