inherit ROOM;

void create()
{
        set("short", "西佛塔");
        set("long", @LONG
你的眼前骤然一变，从黑暗的世界中，进入了一个辉煌灿烂的天地，有如奇迹。
巨大的石柱上，雕着华美而古拙的图案，四壁闪耀着奇光。仔细看去，原来这竟然
本是座巍峨耸立的佛塔，陷入沙漠后，逐渐成了“大石柱”，你做梦也未想到沙漠
之下竟有如此堂皇伟大的建筑。这里，便是汉时辉煌一时的楼兰古国遗址！(过金无
望需交２０两黄金)
LONG
        );
        set("exits", ([ 
		"up" : __DIR__"kongquehe",
		"east" : __DIR__"weststrt3",
	]));
        set("indoors", "loulan");
        set("objects", ([
               __DIR__"npc/cai" : 1,
	]) );

	set("coor/x",-50);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( me->query("class") != "knight" )
        {
	        if( userp(me) && dir=="east" && ob=present("jin wuwang", this_object()) ) 
	        {
	        	if (!REWARD_D->check_m_success(me, "酒色财气")
	        		&& !REWARD_D->riddle_check(me, "酒色财气/cai"))
	        		return notify_fail("金无望一言不发，身形微动，挡在你的身前。\n");
	        }
	}
	return 1;
}


