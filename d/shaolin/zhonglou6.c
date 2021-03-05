// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "钟楼");
        set("long", @LONG
这里象似一间亭子四周空荡荡的，悬铁钟一口，重一万一千斤，铸于金章宗太
和年间，口沿八唇，上铸八卦，一旦敲响，直接九霄，响彻嵩巅。
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"zhonglou5",
]));
        set("objects", ([
                __DIR__"obj/bigzhong" : 1,
                __DIR__"npc/monk52_sentry" : 1,
                __DIR__"npc/monk53_sentry" : 1,	
       ]) );
	set("coor/x",20);
	set("coor/y",-60);
	set("coor/z",40);
	setup();
}


void init(){
	add_action("do_get","get");
}

int do_get(string arg){
	
	object monk, me;
	
	monk = present("shaolin monk");
	if (!monk)	return 0;
	if (!arg)	return 0;	
	if (arg[0..9] == "giant bell" || arg == "all"){
		monk->ccommand("stare");
		return 1;
	}
	
	return 0;
}
	