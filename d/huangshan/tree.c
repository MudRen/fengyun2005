// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "松树");
        set("long", @LONG
这是一颗横生在崖壁上的小松树，树冠不大，枝叶十分茂密，根处盘根错节深
入崖壁，可见年代已久。观望四周，云海雾缭绕，似身处雾中。向上看，除了垂下
来的绳子，无可攀爬之物。
LONG
        );
 	set("objects", ([
		__DIR__"obj/treetop": 1,
	]) );
	set("outdoors", "huangshan");
	set("coor/x",-25);
	set("coor/y",-5);
	set("coor/z",10);
	setup();
}

void init() {
	add_action("do_climb", "climb");
}

int do_climb(string arg) {
    	object obj, me;
    	int i;
 
    	me = this_player();
    	if(!arg || arg=="") return notify_fail("你要爬什么？\n");
    	if(me->is_busy()) return notify_fail("你正在忙！\N");
    	if(arg == "up" || arg == "悬崖" || arg == "峭壁"){
		me->start_busy(2);
    	    	message_vision("$N抓着绳子，稳稳的顺着峭壁爬了上去。\n", me);
        	call_out("fliping",2,me);
	}
	return 1;
}

int fliping(object me){
	object rope, room;
		
    	if( objectp(me) && !me->is_ghost()) {   
	    	tell_object(me,HIY"\n突然间“啪”的一声绳子断裂，急忙间你探手抓住一块突出的岩石继续向上爬去。\n\n"NOR);
        	room = find_object(__DIR__"taoyuan");
        	if(!objectp(room))      	room = load_object(__DIR__"taoyuan");
        	room->set("marks/climb", 0);
        	me->move(__DIR__"taoyuan");
        	message_vision("$N心有余悸地从崖下爬了上来。\n", me);
    	}
        return 1;
}


void reset () {
    	object *inv;
    	object item1, treetop;
    	::reset();
    
    	treetop = present("treetop", this_object());
    	inv = all_inventory(treetop);
    	if( !sizeof(inv) ) {
    		item1 = new(__DIR__"obj/jianzi");
        	item1->move(treetop);
   	}   
}
