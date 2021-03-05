
inherit ROOM;
void create()
{
        set("short", "沼泽地边缘");
        set("long", @LONG
这里是沼泽地的边缘，芦苇很高，长着长长的叶子，开着深褐色绒毛花，桦树
的树皮白白的，精细稀疏的叶子挂在树上。水很浑浊，看不到底，不过，据镇上三
代打鱼为生的渔夫说，水越浑，下面的鱼就越多，每当大雨倾盆的时候还有人见过
三尺长的大白鲤跃出水面。
LONG
        );
        set("exits", ([ 
		"east": __DIR__"swamp2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("objects", ([
	        __DIR__"npc/oldfishman": 1,
	]));
	set("resource/water",1);
   	set("liquid/container","湖水");
   	set("liquid/name","沼泽水");
	set("coor/x",-40);
	set("coor/y",-90);
	set("coor/z",0);
	set("map","taiping");
	setup();

}


void fish_notify(object obj){
   	object me, room, fish, *inv, bait;
	int i;
	
   	me = this_player();
	if (me->is_busy() || me->is_fighting()) {
		tell_object( me, "你现在正忙，哪有空钓鱼。\n");
		return ;
	}
	
	inv = all_inventory(obj);
	if(sizeof(inv) == 0){
		message("vision",me->name() + "掏出了" + obj->name() + "又放了回去。\n", environment(me), me);
     		tell_object(me, obj->name() + "上没有饵怎么可以钓鱼呢 ? \n");		
		return;
	}		
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->query("fish_bait")) {
			bait = inv[i];
      			message_vision("$N挥动了一下," + obj->name() + "在空中划了一道漂亮的弧线, 鱼钩落入了水中. \n" , me);
      			me->start_busy(5);
      			remove_call_out("do_fishing");              
      			call_out("do_fishing", 5, me, bait);			
			return;
		} 
	}
   	tell_object(me, "你用的饵不太对吧 ? \n");			
	return;
}

void do_fishing(object me, object bait){
	object 	fish;

   	if(me && environment(me) == this_object()) {
   		message_vision("$N很快又扯动了一下鱼杆, " , me);
   		switch (random(3)) {
      			case 0:    	message_vision("却什么都没钓上来 ! \n", me);
         				break;
      			case 1:        	message_vision("什么都没钓上来 , 鱼饵却被鱼吃了 !!  \n", me);
						destruct(bait);				
         				break;
      			case 2:
						message_vision("鱼钩上钓到一条大鱼 ！！  \n", me);
         				fish = new(__DIR__"obj/fish");
         				if (fish){
	         				if (!fish->move(me))
	         						fish->move(environment(me));
	         			}
         				destruct(bait);
         				break;
      		}
   	}
	return;
}
