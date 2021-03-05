// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "湖面");
        set("long", @LONG
湖很大，四周的群山在这里看来显得很小，水很清很冷，温柔地环绕在你身体
的四周，天上的白云缓慢地变换着形状，你几乎忘记了时间的存在，然而冰冷的湖
水却把你扯回到现实中，还是不要在这里待的太久。
LONG
        );
   	set("objects", ([
      		__DIR__"npc/frog" : 2,
   	]) );
        set("outdoors","shenshui");
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",20);
	set("underwater",30);
	set("water_damage",10);
	setup();
}

void init()
{
   	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
   	add_action("do_swim", "swim");
}

int do_swim()
{
   	object me, room;
   	int kar, k;
  
   	me = this_player();
   	if( me->is_busy() )
      		return notify_fail("你上一个动作还没有完成。\n");
   	me->start_busy(2);
   	kar = (int)me->query("kar");
   	k = kar - 15; if(k<1) k = 1;
   	message_vision("\n$N奋力向湖边游去!", me);
   	if(random(kar) < k) {
      		message_vision("$N终于湿淋淋地爬到了岸上!\n\n", me);
      		room = find_object(AREA_LAOWU"baishui");
	      	if(!objectp(room)) room = load_object(AREA_LAOWU"baishui");
	      	me->move(room);
	      	message("vision", me->name()+"湿淋淋地从湖里爬了上来。\n", environment(me), me);
   	} else {
      		message_vision("一股暗流又把$N冲了回来!\n", me);
   	}
   	return 1;
}
