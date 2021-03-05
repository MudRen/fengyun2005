inherit ROOM;

void create()
{
        set("short", "北佛塔");
        set("long", @LONG
你的眼前骤然一变，从黑暗的世界中，进入了一个辉煌灿烂的天地，有如奇迹。
巨大的石柱上，雕着华美而古拙的图案，四壁闪耀着奇光。仔细看去，原来这竟然
本是座巍峨耸立的佛塔，陷入沙漠后，逐渐成了“大石柱”，你做梦也未想到沙漠
之下竟有如此堂皇伟大的建筑。这里，便是汉时辉煌一时的楼兰古国遗址！
LONG
        );

        set("exits", ([ 
		"up" : __DIR__"kongquehe",
		"south" : __DIR__"northstrt2",
	]));
        set("objects", ([
		__DIR__"npc/qi" : 1,
	]) );
        set("indoors", "loulan");
	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( me->query("class") != "knight" )
        {
	        if( userp(me) && dir=="south" && ob=present("dugu shang", this_object()) ) 
	        {
	        	if( !me->query_temp("marks/knight_win_dugu")
	        		&& !REWARD_D->check_m_success(me, "酒色财气"))                
	               return notify_fail("独孤伤冷冷道：打赢我，进去；打输了，滚蛋。”\n");
	        }
	}
	return 1;
}
