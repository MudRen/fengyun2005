#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "风云客栈");

	set("long", @LONG
大街尽头，铜门紧闭，一根三丈高的旗杆上，挑起了四盏斗大的灯笼。朱红的
灯笼，漆黑的字：

                   风  云  客  栈    

LONG);
	set("type","house"); 
	set("exits",([
		"south":__DIR__"fyavenue",
		"north":__DIR__"fyhall",
	]) );
        set("outdoors", "chenxiang");
	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",0);
		    
	set("objects",([
     		__DIR__"npc/miao":1,
     		__DIR__"npc/zhao":1,
     		__DIR__"npc/zhang":1,
    	]) );
	setup();
}

int valid_leave(object me, string dir)
{
        if( userp(me) && dir=="north")
        {
        	if(!me->query_temp("marks/longlife_peacockmap")
        		&& !REWARD_D->check_m_success(me,"天上白玉京"))
        	{
        		if(present("miao shaotian", this_object()))
        		{
                    return notify_fail("苗烧天咧嘴怪笑道：活的不耐烦啦？找死啊。\n");
        		}
        		else if(present("zhao yidao", this_object()))
        		{
                    return notify_fail("赵一刀怪眼一翻，喝道：小兔崽子没事回家吃奶去，别跑这多事。\n");   
        		}
        		else if(present("zhang san", this_object()))
        		{
                    return notify_fail("张三嘿嘿笑道：小兔崽子你进去了，爷爷我怎么办。\n"); 
        		}
        	}
        	else
        	{
        		message_vision(HIY"$N一猫身偷偷进入风云客栈。\n\n"NOR,me);
        		return 1;
        	}
        }
	return 1;
}
