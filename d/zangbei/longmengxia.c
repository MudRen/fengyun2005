inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "龙门峡");
        set("long", @LONG
龙门峡位于青铜峡的下游，每当洪水季节，由于峡口中的水位壅高，而出了峡
谷后，河谷突然变宽，水位则骤然下降，于是在龙门形成明显的水位差，故有“龙
门三跌水”之说。沿袭相传的“鲤鱼跳龙门”的故事，就是指跳跃此处的跌水。说
的是小鲤鱼不畏险阻，纷纷跳跃这道通向成龙道路上的门关，又传说能逆流而上游
到这儿的，已是同类中的佼佼者，便有了龙鲤鱼的传说。等到洪水季节过后，这里
成了一片沼泽地，便是渔人争相垂钓的好地方。
LONG
        );
        set("exits", ([ 
			"east": __DIR__"qingtongxia",
		]));
        set("objects", ([
		]) );
		set("outdoors", "zangbei");
        set("coor/x",-510);
        set("coor/y",550);
        set("coor/z",0);
		set("map","zbeast");
		set("dragon_fish", 2);
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
   		
   		if ( query("dragon_fish") && bait->query("fish_bait_real") ){        
	    		message_vision("鱼钩上钓到了一条龙鲤鱼！！！！  \n", me);
	    		add("dragon_fish",-1);
	    		if (query("dragon_fish")<0) set("dragon_fish",0);
	    		fish = new(AREA_TAIPING"obj/dragonfish");
	    		if (fish){
	    			if (!fish->move(me))
	    				fish->move(environment(me));
	    		}
	    		destruct(bait);
        }        
        else {      
	    
   			switch (random(3)) {
      			case 0:    	message_vision("却什么都没钓上来 ! \n", me);
         					break;
      			case 1:    	message_vision("什么都没钓上来 , 鱼饵却被鱼吃了 !!  \n", me);
							destruct(bait);				
         					break;
      			case 2:		message_vision("鱼钩上钓到一条大鱼 ！！  \n", me);
         					fish = new(AREA_TAIPING"obj/fish");
         					if (fish){
	         					if (!fish->move(me))
	         						fish->move(environment(me));
	         				}
         					destruct(bait);
         					break;
         	}
        }
	}
	return;
}

int	reset(){
	set("dragon_fish",2);
	::reset();
}