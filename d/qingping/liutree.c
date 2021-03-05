//XXDER
inherit ROOM;

void create()
{
        set("short", "柳树上");
        set("long", @LONG
柳树很大，由于树横卧在水面上，所以并不高。坐在这里，你的脚几乎可以碰
到水面，微风袭来，柳条轻拂着你的面颊，好似情人的手一般温柔。几条[37m锦鲤[32m在树
下的水中悠闲地游来游去，不远处的小桥倒映在水中，从这里看去别有一番景致。
LONG
        );

   set("exits", ([ /* sizeof() == 4 */
      "down" : __DIR__"northpond",
   ]));
	
	set("item_desc", ([
		"fish":	"哇，好大的鱼儿，如果有钓鱼竿就好了！\n",
		"锦鲤":	"哇，好大的鱼儿，如果有钓鱼竿就好了！\n",
		"黑斑": "这儿太远了，怎么也看不清楚。\n",
		"石头":	"一块大大的太湖石。\n",
		"stone":	"一块大大的太湖石。\n",	
	]));
				
   	set("outdoors", "qingping");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",10);
   	setup();
}

int fish_notify(object obj){
   	object me, room, fish, *inv, bait;
   	int i,llvl;

   	me = this_player();
   	llvl = (int)me->query("kar");

	inv = all_inventory(obj);
	if(sizeof(inv) == 0){
		message("vision",me->name() + "掏出了" + obj->name() + "又放了回去。\n", environment(me), me);
     	tell_object(me, obj->name() + "上没有饵怎么可以钓鱼呢 ? \n");		
		return 1;
	}		
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->query("fish_bait")) {
			bait = inv[i];
      		message_vision("$N坐在树干上静静的开始垂钓。 \n" , me);
      		me->start_busy(3);
      		if(llvl > 15 && random(20) < llvl) {
            		tell_object(me, "无聊中你注意到桥头雪白的石头上似乎有一块黑斑。\n");
            		me->set_temp("marks/bridge", 1);
      		} else if(random(300) < llvl) {
            	tell_object(me, "无聊中你注意到桥头雪白的石头上似乎有一块黑斑。\n");
            	me->set_temp("marks/bridge", 1);
      		}
      		remove_call_out("do_fishing");              
      		call_out("do_fishing", 5, me, bait);			
			return 1;
		} 
	}
   	tell_object(me, "你用的饵不太对吧 ? \n");			
	return 1;
}

void do_fishing(object me, object bait)
{
   object 	fish;

   if(me && environment(me) == this_object()) {
   message_vision("$N很快又扯动了一下鱼杆, " , me);
   switch (random(3)) {
      case 0:
         message_vision("却什么都没钓上来 ! \n", me);
         break;
      case 1:
         message_vision("什么都没钓上来 , 鱼饵却被鱼吃了 !!  \n", me);
         destruct(bait);
         break;
      case 2:
         message_vision("鱼钩上钓着一条鱼 !!  \n", me);
         fish = new(__DIR__"obj/fish");
         fish->move(me);
         destruct(bait);
         break;
      }
   }
   return;
}

