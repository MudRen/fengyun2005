#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", CYN"朱絮桥"NOR);
	set("long", @LONG
小小的朱絮桥，乃是济南城的一大景观。曲折的小桥向湖心的烟水亭延绵
而去，却竟没有可以行人的桥面，只有一片片荷叶飘浮水面，两翼雕花的扶栏
对称相望。小心翼翼地踏着莲叶行在桥上，脚下是潋滟的波光，枕云的倒影，
迎面撩人的湖风也显得格外清扬。
LONG
	);
	set("exits", ([ 
  "west" : __DIR__"bridge1",
  "northeast" : __DIR__"bridge3",
]));
        set("objects", ([
//        __DIR__"npc/surong" : 1,
                        ]) );
    set("outdoors", "jinan");
	set("coor/x",80);
	set("coor/y",60);
	set("coor/z",0);
	setup();
}


int valid_leave(object me, string dir)
{
	object room;

	if (userp(me))
		if (me->query_temp("timer/jinan_bridge") + 1 > time())
		{
			room=find_object(__DIR__"bottom");
			if (!room)
				room=load_object(__DIR__"bottom");
			message_vision(CYN"$N脚下的荷叶微微一滑，一不留神扑通一声落进了湖中。\n\n"NOR,me);
			me->move(room);
			return notify_fail("\n");
		}

		me->set_temp("timer/jinan_bridge",time());
       	return ::valid_leave(me,dir);
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
