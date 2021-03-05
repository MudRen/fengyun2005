inherit __DIR__"no_killing_place";
void create()
{
    set("short", "青青石板路");
    set("long", @LONG
青青石板路蜿蜒地从树林中穿过，青青的石板被山林间的薄雾浸得湿润温泽，
油油的闪着光；石板间的青苔密密地爬满了缝隙，这里很少有人路过，你真想脱了
鞋光着脚丫子在上面跑，体会一下这乡间独有的清凉。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"road3",
        "east" : __DIR__"road5",
        ]));
	set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
    setup();
        replace_program( __DIR__"no_killing_place");
}


