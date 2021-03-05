inherit __DIR__"no_killing_place";
void create()
{
	set("short", "青青石板路");
	set("long", @LONG
青青石板路被山林间的薄雾浸得湿润温泽，油油的闪着光；石板间的青苔密密
地爬满了缝隙，每一块石板就象是用上好的翡翠镶了边。石板路的北面离离的散布
着几户农家，每到吃饭时间淡淡的炊烟随着清风飘入林间。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"fhome",
		"west" : __DIR__"taovillage",
   		"south" : __DIR__"teaplace",
   		"east" : __DIR__"road2",
	]));
	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
    replace_program( __DIR__"no_killing_place");
}
