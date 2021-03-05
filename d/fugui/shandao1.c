inherit ROOM;

void create()
{
	set("short", "山道");

	set("long", @LONG
到了此处，山势渐渐平坦些许，已可大致看到不远的富贵山庄，那是一栋坐落
在山腰上的房子，房子很大，建筑得很堂皇。表示房主一定很有钱。但房子距离吉
祥镇也太远了些，也太偏僻了些，附近简直可说是荒无人烟，距离这房子最近的地
方，就是坟场。
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "southdown":__DIR__"shandao2",
        "northup":__DIR__"damen",
	]) );
	set("objects", ([
       		__DIR__"npc/goldant" : 1,
        ]) );



	set("coor/x",10);
	set("coor/y",180);
	set("coor/z",70);
	setup();
	
}

int valid_leave(object me, string dir)
{
    	object ob;
//      mapping m_family;

        if( userp(me) && dir=="northup" && ob=present("gold ant", this_object()) ) 
        {
        	if( !me->query_temp("marks/goldant")
        		&& !REWARD_D->riddle_check(me,"巧过蚂蚁/金蚂蚁")
            	&& !REWARD_D->check_m_success(me,"巧过蚂蚁"))        		
                	return notify_fail("金蚂蚁双手一拦，哼的一声，“富贵山庄里还藏着那该死的燕七，
闲杂人等还是莫要趟这番混水的好。”\n");
        }
		return ::valid_leave(me,dir);
}