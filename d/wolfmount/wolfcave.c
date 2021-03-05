inherit ROOM;

void create()
{
	set("short", "狼窝");

	set("long", @LONG
这山洞的入口虽然窄得只能爬行，但里面倒是十分宽敞，有八九丈纵深，中间
透入一线天光，宛似天窗一般，令你得以凝神观望这洞中天地，四处堆积着不少野
狼的残余食物，腐肉白骨，甚是腥臭。
LONG);

	set("item_desc", ([
		"山洞": "这个山洞全无出路，只有一个洞口似乎可以爬下去（ｃｒａｗｌ）。\n",
        "cave" : "这个山洞全无出路，只有一个洞口似乎可以爬下去（ｃｒａｗｌ）。\n",
//        "洞口": "这个洞口高悬在山壁上，看来只能爬下去（ＣＲＡＷＬ）。\n",
 	
    ]) );
	set("exits", ([
	])); 
	set("objects",([
          __DIR__"npc/sanlang":1,
          __DIR__"npc/yaomei":1,
            __DIR__"npc/xiaowan":1,
   	]) );
    set("indoors", "wolfmount");
	set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",-10);
	setup();
}

void init()
{
	add_action("do_crawl", "crawl");
}

int do_crawl(string arg){
    object 	me;

	if(!arg) {
		write("你要爬向哪里？\n");
		return 1;
	}
    if( arg == "down" || arg == "山洞"|| arg == "out"|| arg== "cave" ){
		me = this_player();
		message_vision("$N抓着山壁上的杂草，慢慢的爬下去。\n", me);
		me->start_busy(2);
        	call_out("fliping",2,me);
        	me->stop_busy();
        	return 1;
    } else {
        me = this_player();
        tell_object(me, "你不可以爬"+arg+"。\n");
        return 1;
    }
}

int fliping(object me)
{
	object room;
	if( !me->is_ghost()) 
	{
		message_vision("$N慢慢爬出山洞。\n", me);
		room = find_object(__DIR__"wolfslope");
		if(!objectp(room)) room= load_object(__DIR__"wolfslope");
		me->move(room);       
	}
        return 1;
}
