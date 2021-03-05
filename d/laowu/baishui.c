// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "白水湖");
        set("long", @LONG
走近来看，原来水色还是青青绿色，只是倒映天上白云，所以远远望来，
便是一片白色。湖边不见草木，水中鲜见游鱼，显得甚是奇怪，更兼微风轻拂
之下，竟然不见水面晃动，令人不由暗暗生奇。
LONG
        );
   	set("exits", ([ 
      		"west" : __DIR__"valley",
   	]));
   	set("objects", ([
		__DIR__"npc/bear": 1,
	]) );
   	set("outdoors","laowu");
	set("coor/x",190);
	set("coor/y",190);
	set("coor/z",20);
	setup();
}

void init()
{
   	add_action("do_swim", "swim");
}

int do_swim(string arg)
{
   	object me;
	me = this_player();
   	message_vision("$N跳入湖水中，", me);
   	tell_object(me, "湖水冷的刺骨，你不由地打了个寒战，赶紧回到了湖边。\n");
   	message("vision", "打了个寒战，又飞快地爬上了岸。\n", environment(me), me);
   	me->receive_damage("kee",50);
   	me->set_temp("last_damage_from","在白水湖里冻死了。\n");
   	return 1;
}

void kite_notify(object obj, int i)
{
   	object  me, room;
   	int j;
	
   	me = this_player();
   	message_vision("突然一阵微风拂过"+obj->name()+"缓缓的升了起来，越来越高。\n\n" , me);
	tell_object(me, me->name()+"手中的"+obj->name()+"越飞越高。 \n");
	message_vision("只听一阵清悦的哨音从高空传过！ \n", me);
	call_out("boat_come", 2, me);
	destruct(obj);
   	return; 
}

void boat_come(object me)
{
   	object  boat, *inv, ob;
   	int i;

   	if (query("exits/down")) return ;
   	if (!objectp(boat=find_object(__DIR__"boat")))
      		boat=load_object(__DIR__"boat");
   		inv=all_inventory(boat);
   	for(i=0; i<sizeof(inv); i++) {
      	ob = inv[i];
      	if(living(ob)){
         	message("vision","半晌，湖上还是没有丝毫动静。\n",this_object()); 
         	return;
      	}
   	}
   	message("vision","过了半晌，一叶小舟缓缓地从雾中荡出，靠到了湖边。\n",this_object()); 
   	boat->set("exits/up",__DIR__"baishui");
   	set("exits/down",__DIR__"boat");
   	call_out("boat_leave",10,boat);
   	return ;
}

void boat_leave(object boat)
{
	if (query("exits/down")) delete("exits/down");
	if (boat->query("exits/up")) boat->delete("exits/up");
	message("vision","一阵微风拂过，小船荡离了岸边。\n",this_object()); 
	message("vision","一阵微风拂过，小船荡离了岸边。\n",boat); 
        return;
}

int valid_leave(object me, string dir)
{
   object *inv, boat, ob;
   int i;

   if (userp(me) && dir == "down") {
      boat=find_object(__DIR__"boat");
      if (!objectp(boat))
         boat=load_object(__DIR__"boat");
         inv=all_inventory(boat);
            for(i=0; i<sizeof(inv); i++) {
               ob = inv[i];
               if(living(ob)){
                  tell_object(me, "船太小了，只能乘坐一个人。\n");      
                  return notify_fail("");
               }
           }
   }
   return 1;
}
