inherit __DIR__"no_killing_place";
void create()
{
	set("short", "青青石板路");
    set("long", @LONG
青青石板路被山林间的薄雾浸得湿润温泽，油油的闪着光；石板间的青苔密密
地爬满了缝隙。石板路的北面散落着几户农家，每到夕阳西下的时候，站在这里就
可以闻到饭菜的香味。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"nongjia",
   		"west" : __DIR__"road1",
   		"east" : __DIR__"road3",
   		"south" : __DIR__"linjian",
	]));
	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program( __DIR__"no_killing_place");
}


