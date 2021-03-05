// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "掖门");
        set("long", @LONG
这是一座小门，平常都是关着的，和马道相连，马匹车辆可以从这里直达天王
殿，八字墙和正门相掩映，别有一番风味。这里进去便是长长的马道。（给这儿的
和尚２０两银子可从此处进少林） 
LONG
        );
        set("exits", ([ 
  "eastdown" : __DIR__"shandan",
  "northeast" : __DIR__"yingbi",
]));
        set("objects", ([
                __DIR__"npc/monk4" : 2,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",-10);
	setup();
}


int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me))
        {
	        if( !me->query_temp("shaolin") 
	        	&& me->query("class") != "shaolin" 
	        	&& dir == "northeast" 
	        	&& ob=present("shaolin monk", this_object()))
        	{
                	inv = all_inventory(me);
                	for(i=0; i<sizeof(inv); i++)
                        	if(inv[i]->query("shaolin_cloth") && (int)inv[i]->query("equipped"))
	                        	return 1;
                	return notify_fail(ob->name()+"向你拱手道：没有游山牌，非少林弟子不可入内！！\n");
        	}
        	return 1;
        }
        else 
        	return 1;
}