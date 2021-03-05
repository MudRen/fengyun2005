// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "排云亭");
        set("long", @LONG
六角小亭依崖而建，亭柱之间是半人高的栏杆，可以坐下休息观云，也可以防
止游人坠入悬崖。黄山常年处于云雾之中，云来雾去，变幻莫测，时而是风平浪静
的一片汪洋，时面波涛汹涌，白浪排空。（１０两白银洗少林匪２０点，１两黄金
可清全部少林匪。） 
LONG
        );
    set("exits", ([ 
		"northeast" : __DIR__"guangming",
	]));
    set("objects", ([
    	__DIR__"npc/monk" : 1,
    ]) );
        set("indoors", "huangshan");
	set("coor/x",-100);
	set("coor/y",-20);
	set("coor/z",30);
	set("no_lu_letter",1);
	setup();
        replace_program(ROOM);
}
