inherit ROOM;
void create()
{
        set("short", "水井中");
        set("long", @LONG
水井很深，冰凉的井水浸得你骨头都发麻，一只随你一快儿掉下来的水桶一起
一伏，在水中荡漾。一线天光从你头顶上射下来，那样微弱，你都不知道还有没有
生还的机会．．．
LONG
        );
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",-10);
        setup();
}

void init()
{
   add_action("do_climb", "climb");
   if(interactive(this_player()))
   call_out("do_flush",60,this_player());
}

int do_climb(string arg)
{
   object me, room;

   me = this_player();
   if(me->is_busy())
	return notify_fail("你现在没空！\n");
   switch (random(3)) {
   case 0:
      message_vision("$N手脚并用地往上爬，才爬到一半，一失手又摔了下来。\n", me);
      me->receive_damage("gin",20);
	  me->set_temp("last_damage_from","在桃源的井里老死了。\n");
	  me->start_busy(5);
      break;
   case 1:
      message_vision("$N手脚并用地往上爬，眼看快到井口了，结果一失手又摔了下来。\n", me);
      me->receive_damage("gin",40);
		me->set_temp("last_damage_from","在桃源的井里老死了。\n");
		me->start_busy(5);
      break;
   case 2:
      if(!arg || (arg != "上" && arg != "up" && arg!= "well")) return 0;
      room = find_object(__DIR__"cyard1");
      if(!objectp(room)) room=load_object(__DIR__"cyard1");
      me->move(room);
      message_vision("$N浑身湿淋淋地从水井中爬了上来。\n", me);
      break;
   }
   return 1;
}

void do_flush(object me)
{
   object room;

   if(!me || environment(me) != this_object())
   return;
   tell_object(me,"\n你突然发觉井里的水居然在流动！\n\n");
   tell_object(me,"水流好象带着你从井底的一个暗道里涌出．．．\n");
   tell_object(me,"你陷入一片完全的黑暗之中，心中充满了恐惧．．．\n\n");
   room = find_object(__DIR__"tunnel");
   if(!objectp(room)) room= load_object(__DIR__"tunnel");
   me->move(room);
}


