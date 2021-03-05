inherit __DIR__"no_killing_place";
void create()
{
    set("short", "青青石板路");
    set("long", @LONG
青青石板路被山林间的薄雾浸得湿润温泽，油油的闪着光；石板间的青苔密密
地爬满了缝隙。石板路的北面是一个小小的院落，原木围做的篱笆上爬满了青藤，
上面零星点缀着几朵红色的花。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"anju",
        "west" : __DIR__"road2",
        "east" : __DIR__"road4",
        ]));
	set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
    setup();
        replace_program( __DIR__"no_killing_place");
}
