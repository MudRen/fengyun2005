
inherit ROOM;

void create()
{
	set("short", "洞内");
	set("long", @LONG
洞里十分干燥，脚下不是泥地，倒仿似是用青石板铺成的，踩上去砰砰作响，
没过数十尺就有些乳白色的光晕，不象是灯火，而象是石头里发出的荧光。洞不深，
前面有一丝阳光照进来。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"hole4",
  		"south" : __DIR__"hole",
	]));
	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
