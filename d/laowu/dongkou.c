// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "洞口");
        set("long", @LONG
你站在一个山坡上，背后是爬满了各式各样的藤萝的峭壁，有些藤萝还开着鲜
艳的花朵，就象是一幅巨大的挂毯把峭壁遮在了后面。往远处看，只见群山叠起，
云雾缭绕，山峰都隐没在一片白茫茫的雾海之中。
LONG
        );
   set("exits", ([ 
      "north" : __DIR__"gudi",
   ]));
   
   set("item_desc", ([
      "藤萝" : "藤萝上开着紫色的花朵，透过茂密的藤萝，你隐约可以看见一块大石。\n",
      "vine" : "藤萝上开着紫色的花朵，透过茂密的藤萝，你隐约可以看见一块大石。\n",
      "峭壁" : "峭壁很高并且很陡，几乎是不可能爬的上去的。\n",
      "cliff" : "峭壁很高并且很陡，几乎是不可能爬的上去的。\n",
   ]) );

   	set("outdoors", "laowu");
	set("coor/x",150);
	set("coor/y",160);
	set("coor/z",10);
	setup();
}

void init()
{
   	add_action("do_push", "push");
}

int do_push(string arg)
{
   	object me, obj;
   	int flvl;

   	me = this_player();
   	flvl = (int)me->query_str();
   	if(!arg || (arg != "stone" && arg != "石头" && arg != "rock"))
      	return 0;
   	if (flvl >= 20) {  
    	if (!query("exits/enter")) {
         	message_vision("$N运力于双臂, 使出浑身的力气向藤萝后的大石推去！ \n", me);
         	message_vision("大石慢慢向旁边滑去, 露出了一个洞口。 \n", me);
         	set("exits/enter", __DIR__"midao8");
         	call_out("close_path", 2);      
         	return 1;
      	}
   	}
   	else {
      if (!query("exits/enter")) {
      	message_vision("$N运力于双臂, 使出浑身的力气向藤萝后的大石推去，石头微微晃动了几下！ \n", me);
         return 1;
      }
   }
   return 0;
}


void close_path()
{
   if(!query("exits/enter") ) return;
   message("vision", "只听咯吱吱，石头又滑了回来挡上了洞口。\n", this_object() );
   delete("exits/enter");
}
