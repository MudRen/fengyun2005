inherit ROOM;

void create()
{
	set("short", "风云道");

	set("long", @LONG
“一入风云岁月催”，这儿是连接[33m沉香镇[32m和[33m南海[32m的风云道，暗褐色的道路，从
这里开始婉蜒伸展，穿过翠绿的树林，沿着湛蓝的湖水，一头伸展向闹市，一头绕
过黑漆漆的森林通向远方。远山在阴瞑的天色中看来，仿佛在雾中，更加美丽神秘。  
LONG);

	set("type","road");
	set("exits",([
		"north":__DIR__"fyhotel",
		"south":__DIR__"cxe2",
		]) );
        set("outdoors", "chenxiang");
	set("coor/x",20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
