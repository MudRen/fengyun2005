// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "海上");
        set("long", @LONG
四周是茫无边际的[33m海水[32m，看不到任何的船只或路地，你被这无边无际的海水包
围着，随着波浪而起浮，苦涩的海水不时地灌入你的口中，你不由地感到了自己的
渺小，不知还有多大的生还机会。
LONG
        );
   
   set("item_desc", ([
   		"海水":		"既然到了海里,总是应该试着游泳了（swim）\n",
   	]));	
   		
   set("objects", ([
   ]) );   

	set("coor/x",1100);
	set("coor/y",-12640);
	set("coor/z",-60);
   setup();
}

void init()
{
   add_action("do_swim", "swim");
}

int do_swim(string arg)
{
   object me, room;
   int kar, k;
  
   me = this_player();
   if( me->is_fighting() )
      return notify_fail("你在战斗中！\n");
   if( me->is_busy() )
      return notify_fail("你上一个动作还没有完成。\n");
   
   me->start_busy(2);
   
   message_vision("\n$N奋力向前游去!\n", me);
   
      tell_object(me, "远远的你似乎看到了一片陆地，你用尽所有的力气向那儿游去。\n");
      message_vision("$N终于湿淋淋地爬到了岸上!\n\n", me);
      room = find_object(AREA_EASTCOAST"seaside");
      if(!objectp(room)) room = load_object(AREA_EASTCOAST"seaside");
      me->move(room);
      message("vision", me->name()+"湿淋淋地从海里爬了上来。\n", environment(me), me);
      return 1;
}
