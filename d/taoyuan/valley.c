inherit ROOM;

void create()

{

        set("short", "山谷");
        set("long", @LONG
树林到了此处逐渐变得稀疏起来，眼前赫然出现一座千层叠翠、万里点苍的山
峰，围成一处幽谷，中有一泓清潭，泉水从峰间奔流而下，喷珠泄玉，直入清潭。
几只白尾巴的野兔，正在潭边悠闲的喝水。此处空气清凉湿润，沁人心肺，四周却
看不见任何明显的出路。
LONG
        );

	set("objects", ([
	__DIR__"npc/rabbit1": 3,
        ]) );

        set("outdoors","taoyuan"); 
	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
void init()
{
   add_action("do_west", "west");
   add_action("do_catch", "catch");
   add_action("do_around", "around");
}



int do_around(string arg)

{

   object me, room;
   int i;
   string *rooms = ({"valley", "valley1", "valley2", "valley3"});
   i = random(4);
   me = this_player();
   tell_object(me, "你转来转去，也没找到出口，你迷了路！！\n\n");
   room = find_object(__DIR__ + rooms[i]);
   if(!objectp(room)) room=load_object(__DIR__ + rooms[i]);
   me->move(room);
   return 1;
}



int do_catch(string arg)

{
   object rabbit, me, room;
   me = this_player();
   if(!arg || arg != "野兔" && arg != "rabbit" ) return 0;
   rabbit = present("rabbit", this_object());
   if(!objectp(rabbit)) return 0;
   switch ( random (7)) {
   case 0:
      message_vision("$N向前一扑！野兔往後一跳，$N扑了个空。 \n", me); 
      break;
   case 1:
      message_vision("$N向右一扑！野兔向左一闪，$N扑了个空。 \n", me); 
      break;
   case 2:
      message_vision("$N向左一扑 , 野兔向右一闪，$N扑了个空。\n", me); 
      break;
   case 3:
      message_vision("$N左扑右挡紧紧地跟着野兔，深怕一转眼就不见了．．．\n", me);
   	break;
   case 4:
      message_vision("$N合身扑向野兔 , 野兔向旁边一窜躲开了你，$N收势不住摔了个嘴啃泥。  \n", me);
   	break;
   case 5:
      message_vision("$N蹑手蹑脚地朝野兔摸过去，想从后面抓住它，野兔机灵地向前一冲，$N没成功。\n", me);
	break;
   case 6:
      message_vision("$N猛往前一扑 , 野兔向前一冲 , 从$N的胯下飞快的钻了过去。 \n", me); 
      message_vision("$N调头便向野兔逃跑的方向追去.... \n", me); 
      message_vision("\n野兔三转两转，倏地一下不见了踪影。\n\n", me); 
      message("vision", me->name() + "紧紧跟着野兔转眼不见了踪影。\n", environment(me), me);
      room = find_object(__DIR__"fenghuo");
	      if(!objectp(room)) room=load_object(__DIR__"fenghuo");
      me->move(room);
//    destruct(rabbit);
      break;
   }
   return 1;
}



int do_west(string arg)

{
        object me;
        object room;
        me = this_player();
        message_vision("$N往西边的树林走去 . \n", me);
        room = load_object(__DIR__"taolin2");
        if(room) me->move(room);
        return 1;
}
