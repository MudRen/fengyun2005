inherit ROOM;
void create()
{
        set("short", "乌拉泊南城门");
        set("long", @LONG
乌拉泊自唐元以来就是这里最热闹的城镇，这里的巴札，以其历史悠久而闻名
于世，迄今已有过千年的历史。这里真可谓“十里长街，万商云集”。往北就是大
巴札，再往北就出城了。
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"bazha3",
  		"south" : __DIR__"tulu2",
	]));
        set("objects", ([
        __DIR__"npc/police2" : 1,
	__DIR__"npc/gate_soldier": 2,
                        ]) );
        //set("no_pk",1);
        
        set("outdoors", "xinjiang");
	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}


int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	int i;
	if( userp(me) && ob=present("garrison", this_object()))
	{
		if( dir == "north" )	{
			inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++)	{
				if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
					return notify_fail(ob->name()+"向你喝道：不可手持兵器入城！\n");	
			}
		}
	
        	if ( dir == "north" && me->is_naked())  {
			if (me->query("age")<=11)
				 tell_object(me,ob->name()+"皱着眉头说：小孩子光着屁股跑来跑去，像什么样子！\n\n");
			else
				return notify_fail(ob->name()+"向你喝道：赤身裸体招摇过市，成何体统！！\n");
		}
        	
               	return 1;
	}
	else
		return 1;
				
}