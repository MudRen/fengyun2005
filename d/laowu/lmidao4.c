// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山洞秘道");
        set("long", @LONG
这里已是秘道的尽头，除了来路没有任何出口，往前看，石壁上有个洞口，洞
口不大，只容得一人进出，但却被一块大石从外面挡住，除此之外你看不到任何有
可能出去的地方。
LONG
        );
        set("exits", ([ 
		  "southwest" : __DIR__"lmidao2",
	]));
   	set("item_desc", ([
      		"stone" : "一块大石挡住了一个一人大小的洞口。 \n",
      		"rock" : "一块大石挡住了一个一人大小的洞口。 \n",
		"石头" : "一块大石挡住了一个一人大小的洞口。 \n",
   	]) );
	set("coor/x",110);
	set("coor/y",40);
	set("coor/z",0);
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
      	if (!query("exits/out")) {
	         message_vision("$N运力于双臂, 使出浑身的力气向大石推去！ \n", me);
	         message_vision("大石慢慢向旁边滑去, 露出了一个洞口。 \n", me);
	         set("exits/out", __DIR__"dongkou");
	         call_out("close_path", 2);      
	         return 1;
      	}
   	}
   	else {
      		if (!query("exits/out")) {
      			message_vision("$N运力于双臂, 使出浑身的力气向大石推去，石头纹丝不动！ \n", me);
         		return 1;
      		}
   	}
   	return 0;
}


void close_path()
{
   	if(!query("exits/out") ) return;
   	message("vision", "只听咯吱吱，石头又滑了回来挡上了洞口。\n", this_object() );
   	delete("exits/out");
}


