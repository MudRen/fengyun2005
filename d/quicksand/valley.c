
inherit ROOM;

void create()
{
        set("short", "死谷");
        set("long", @LONG
死谷是一个名副其实的死地，四面峭壁如削，寸草不生。除了有几只飞鸟从空
中掠过，谷内死气沉沉，全无生机。令人惊奇的是，这儿居然有一间小小的茅屋，
屋里居然还有人住着。
LONG
        );
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/redlama" : 1,
        ]) );

	set("coor/x",-1130);
	set("coor/y",-20);
	set("coor/z",-10);
	setup();
}
void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "valley" || arg == "up" || arg == "死谷")
        {
        me = this_player();
        if (me->query_temp("climbup")) {
	        	write("你已经在爬了。\n");
	        	return 1;
	        	}
        message_vision("$N抓着突出的石角，慢慢的顺着谷壁爬了上去。\n", me);
        me->start_busy(2);
        call_out("fliping",2,me);
//      me->stop_busy();
	me->set_temp("climbup",1);
        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
void fliping(object me)
{
	object room;
	if( !me->is_ghost()) {
        room = find_object(__DIR__"cliff");
	if(!objectp(room)) room= load_object(__DIR__"cliff");
	me->move(room);     
	message_vision("$N顺着谷壁爬了上来。\n", me);  
	}
        me->delete_temp("climbup");
        return;
}

