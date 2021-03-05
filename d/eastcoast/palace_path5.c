
inherit ROOM;

void create()
{
        set("short", "云海孤舟");
        set("long", @LONG
云，翻腾在脚下，象拍岸的波浪，又象潺潺的流水，此起彼伏，无边无际。你
就象乘着一条孤舟在云海中漂荡，不知道是水在流，还是船在走。东北边，那日出
之颠，就是传说中的神秘的[33m『帝王谷』[32m。南面另有一条小路,弯弯曲曲地通向远方。
LONG
        );
        set("exits", ([ 
		   "northeast" : AREA_PALACE"entrance",
		   "southdown" : __DIR__"troad0a",
		   "westdown"  : __DIR__"palace_path4",
	]));
        set("outdoors", "palace");

	set("coor/x",260);
	set("coor/y",0);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}

