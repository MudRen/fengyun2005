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
  "south" : __DIR__"bridge3",
  "enter" : __DIR__"pavilion",
]));
	set("item_desc", ([
	"烟水亭":"朱絮桥已到尽头，再向前就是翘檐揽月，尖顶簪霞的湖心烟水亭。\n",
	"pavalion":"朱絮桥已到尽头，再向前就是翘檐揽月，尖顶簪霞的湖心烟水亭。\n",
	]) );
		set("objects", ([
//        __DIR__"npc/surong" : 1,
        __DIR__"npc/thief" : 1,
                        ]) );
    set("outdoors", "jinan");
	set("coor/x",100);
	set("coor/y",120);
	set("coor/z",0);
	setup();
}

void init()
{
   add_action("do_jump", "jump");
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


int do_jump(string arg)
{
   object me, room;
   int ml;

   me = this_player();
   ml = me->query_skill("move",1);

      if(!arg || (arg != "up" && arg != "pavalion" && arg != "烟水亭" && arg != "烟水亭顶")) {
			tell_object(me,"你要向哪里跳？\n");
			return 1;
	}

      if (ml >= 170)
	  {
		 message_vision(CYN"$N一纵身，体态轻盈地向烟水亭顶跃去．．．\n"NOR,me);
         room = find_object(__DIR__"pavtop");
         if(!objectp(room)) room = load_object(__DIR__"pavtop");
         me->move(room);
         message("vision", me->name()+"身法美妙地跳了上来。\n", environment(me), me);
         return 1;
      }

	message_vision(CYN"$N提气欲向烟水亭上纵去．．．却忘了脚下是荷叶，根本无从着力。\n"NOR,me);
	room=find_object(__DIR__"bottom");
	if (!room)
		room=load_object(__DIR__"bottom");
	message_vision(CYN"$N手舞足蹈地打了个转儿，凌空跃起三寸，姿势优美地掉进了湖里。\n"NOR,me);
	me->move(room);
    return 1;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
