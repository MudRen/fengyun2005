inherit ROOM;

void create()
{
        set("short", "崖底");
        set("long", @LONG
四周都是悬崖峭壁，上边生满一人多高的荆棘，看来是没有希望爬上去。脚下
是只能一个人容身的空间，铺满柔软的细沙。几只秃鹰在高高的蓝天上翱翔，此时
此刻，你才体会到自由的快乐。
LONG);

        set("type","road");
       set("outdoors", "wolfmount");
	set("coor/x",80);
	set("coor/y",20);
	set("coor/z",-60);
	setup();

}

void init(){
	add_action("do_climb", "climb");
}

int do_climb(){
	object me, room;
	int i;
	me = this_player();
	i = me->query_skill("move",1);
	if(i<1){
		message_vision("$N抬头看了看四周的峭壁，不由得长叹了一口气。\n", me);
		tell_object(me, "以你目前的身手看来是没有可能爬的上去了。\n");
		tell_object(me,"（后悔啊，为什么连一点轻功都不肯学呢？）\n");
	} else {
		message_vision("$N抬头看了看四周的峭壁，深深呼吸了几下向上爬去。\n", me);
		me->start_busy(3);	
		call_out("do_fliping", 3, me);
	}
	return 1;
}
int do_fliping(object me){
    object room;
    
    if( !me->is_ghost()) {   
    	room = find_object(__DIR__"moonrock");
    	if(!objectp(room)){
    		room = load_object(__DIR__"moonrock");
    	}
    message("vision", me->name()+"越爬越高身形渐渐消失不见了。\n", environment(me), me);
    me->move(room);
    message_vision("$N顺着谷壁爬了上来。\n", me);
    }
    return 1;
}
