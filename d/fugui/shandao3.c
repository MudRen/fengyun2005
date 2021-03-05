#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "山道");

	set("long", @LONG
你走在去富贵山庄的山道上，下可望见吉祥镇那袅袅炊烟，隐隐还可听到镇中
的狗吠鸡鸣，一抬头，又可看见几个或是蜈蚣状，或是老鹰状的风筝高高飞舞在蓝
天白云中。山风徐徐，白云悠悠，不觉感觉悠闲自得。往东北探头望去，已可隐约
看见富贵山庄的铜漆大门。往西则是一片密林。
LONG);

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"west":__DIR__"milin1",
        "southdown":__DIR__"shandao4",
		"northeast":__DIR__"shandao2",
	]) );
	set("objects", ([
    	    __DIR__"npc/whiteant" : 1,
        ]) );

	set("coor/x",0);
	set("coor/y",160);
	set("coor/z",60);
	setup();
}

void init()
{	object ob;
	string outexit;
	if( interactive( ob = this_player()))
	{
		if(query("exits/west")) delete("exits/west");
		outexit = __DIR__"milin"+(string)(1+ random(25))+ ".c";	
		set("exits/west", outexit);
	}
}

int valid_leave(object me, string dir)
{
    	object ob;
        mapping m_family;
        if( userp(me) && dir=="northeast" && ob=present("white ant", this_object()) ) 
        {
            if( !me->query_temp("marks/whiteant")
            	&& !REWARD_D->riddle_check(me,"巧过蚂蚁/白蚂蚁")
            	&& !REWARD_D->check_m_success(me,"巧过蚂蚁"))
                 	return notify_fail("白蚂蚁双手一拦，哼的一声，“富贵山庄里还藏着那该死的燕七，\n\n闲杂人等还是莫要趟这番混水的好。”\n");
		}
	
		if ( dir == "west")
			tell_object(me,HIG"你已经进入了富贵密林，如果迷路了可以用leave指令离开。\n\n"NOR);
	
		return 1;
}
