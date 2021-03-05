// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "桃源亭");
        set("long", @LONG
亭子紧靠桃花峰的边缘，亭子不大，里面空无一物，向下望去是陡峭的崖壁，
一颗小松树横生在下面的崖壁上，树虽不大，但根处盘根错节深入崖壁，可见年代
已久。此亭最佳之处在于可以静心欣赏黄山三名瀑之一的“人字瀑”，远看过去，
瀑布倾泄，恰好是个人字，煞是有趣。
LONG
        );
   	set("exits", ([ 
  		"northeast"  : __DIR__"taohua",
	]));
    	set("objects", ([
    	__DIR__"npc/girl": 1,
    	]) );
	set("marks/climb", 0);
    	set("indoors", "huangshan");
	set("coor/x",-25);
	set("coor/y",-5);
	set("coor/z",20);
	setup();
}

void init() {
	add_action("do_climb", "climb");
}

int tie_notify(object obj) {
	
	object me;
	
	me = this_player();
	message_vision("$N把" + obj->name() + "绑到了亭子栏杆上，绳子的一头垂到悬崖下。\n", me);
	set("long", @LONG
亭子紧靠桃花峰的边缘，亭子不大，里面空无一物，向下望去是陡峭的崖壁，
一颗小松树横生在下面的崖壁上，树虽不大，但根处盘根错节深入崖壁，可见年代
已久。亭子靠崖壁的栏杆上绑着一条藤绳，绳子的一头垂到悬崖下。
LONG 
	);
	set("marks/climb", 1);
	return 1;
}

int do_climb(string arg) {
    	object /*obj,*/ me;
//  	int i;
 
    	me = this_player();
    	if(!arg || arg=="") return notify_fail("你要爬什么？\n");
    	if(me->is_busy()) return notify_fail("你正在忙！\N");
    	if(arg == "down" || arg == "悬崖" || arg == "峭壁"){
		if(query("marks/climb") == 1) {
			me->start_busy(2);
    	    		message_vision("$N抓着绳子，稳稳的顺着峭壁爬了下去。\n", me);
        		call_out("fliping",2,me);
	    	} else {
	    	message_vision("$N探头向崖下看了看，不由得摇了摇头。\n", me); 
        }
    }                    
	return 1;
}

int fliping(object me)
{
	object room;
        if( objectp(me) &&  !me->is_ghost()) {   
        	room = find_object(__DIR__"tree");
        	if (!room) room = load_object(__DIR__"tree");
        	me->move(__DIR__"tree");
        	message_vision("$N顺着垂下的绳子，稳稳的爬了下来。\n", me);
        }
        return 1;
}


void reset(){
	::reset();
    	set("long", @LONG
亭子紧靠桃花峰的边缘，亭子不大，里面空无一物，向下望去是陡峭的崖壁，
一颗小松树横生在下面的崖壁上，树虽不大，但根处盘根错节深入崖壁，可见年代
已久。此亭最佳之处在于可以静心欣赏黄山三名瀑之一的“人字瀑”，远看过去，
瀑布倾泄，恰好是个人字，煞是有趣。
LONG
    );	
	set("marks/climb", 0);
}