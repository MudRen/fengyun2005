inherit ROOM;

void create()
{
	set("short", "山坳");
	set("long", @LONG
南北大道西侧云雾缭绕中山峰隐现，这里是一处山坳，往东就是通往风云城的
南北大道，向西是山路，一条蜿蜒的小径往北展开。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"westup" : __DIR__"road1",
  		"eastdown" : AREA_LAOWU"road2",
]));
	set("outdoors", "taoguan");
	set("coor/x",10);
	set("coor/y",-110);
	set("coor/z",-70);
	setup();
	replace_program(ROOM);
}
