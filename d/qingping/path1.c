inherit ROOM;
void create()
{
        set("short", "荒野小径");
        set("long", @LONG
小路蜿蜒的伸向远方，穿入树林，小路渐渐被荒草淹没再也辨不出痕迹。四周
的树木却越来越密集，虽没有遮天蔽日，却让人感到一种阴森森接近死亡的气息。
这里连虫鸟都很稀少，更不要说是人踪。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
	   "west" : __DIR__"path",	
		"east" : __DIR__"forest4",
   ]));
	set("outdoors","qingping");
	set("coor/x",40);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

