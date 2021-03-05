inherit ROOM;

void create()
{
	set("short", "山道");

	set("long", @LONG
你走在去富贵山庄的山道上，下可望见吉祥镇那袅袅炊烟，隐隐还可听到镇中
的狗吠鸡鸣，一抬头，又可看见几个或是蜈蚣状，或是老鹰状的风筝高高飞舞在蓝
天白云中。山风徐徐，白云悠悠，不觉感觉悠闲自得。
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "eastdown":__DIR__"shandao5",
        "northup":__DIR__"shandao3",
	]) );
	
	set("objects", ([
        	__DIR__"npc/redant" : 1,
        ]) );
	set("coor/x",0);
	set("coor/y",150);
	set("coor/z",50);
	setup();
	
}

int valid_leave(object me, string dir)
{
    	object ob;
        mapping m_family;
        if( userp(me) && dir=="northup" && ob=present("red ant", this_object()) ) 
        {
            if( !me->query_temp("marks/redant")
           // 	&&!me->query_temp("marks/红蚂蚁")
            	&&! REWARD_D->riddle_check(me,"巧过蚂蚁/红蚂蚁")
            	&&! REWARD_D->check_m_success(me,"巧过蚂蚁"))
                return notify_fail("红蚂蚁双手一拦，哼的一声，“富贵山庄里还藏着那该死的燕七，
闲杂人等还是莫要趟这番混水的好。”\n");
        }
		return 1;
}
