inherit ROOM;
void create()
{
    set("short", "深井底");
    set("long", @LONG
下到井底，才发现这里却别有洞天，井底并不潮湿，铺了许多稻草，有一桌一
椅一床，桌上有酒，椅上有衣，床上有被，壁上挂着一串珠子，竟然发着幽幽的蓝
光，把个井底照的亮堂堂的。
LONG
        );
    set("objects",([
        __DIR__"npc/gudongsan":1
    ]));
        set("coor/x",-460);
		set("coor/y",620);
		set("coor/z",-10);
    setup();

}

void init()
{
   add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        
        if( arg == "上" || arg == "up" || arg == "well")
        {
	        me = this_player();
    	    if (me->is_busy()){
        		tell_object(me, "你现在正忙。\n");
        		return 1;
        	}
            message_vision("$N抓着井壁艰难地向上爬去。\n", me);  
          	me->start_busy(2);
        	call_out("fliping",3,me);
        	return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}


int fliping(object me)
{
	if (!me || me->is_ghost())	return 1;
	me->move(__DIR__"banditcamp3");
    message_vision("$N从水井中爬了上来。\n", me);
	return 1;
}
