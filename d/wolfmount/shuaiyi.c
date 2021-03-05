inherit ROOM;

void create()
{
	set("short", "率意厅");

	set("long", @LONG
这是间七丈宽、二十七丈长的大厅，当你走进竹篱时，实在想不到那几间草堂
后竟有这么样一个地方。大厅里空无一物，四壁洁白如雪，惟有一侧挂着幅率意图。
大厅另外一端却有扇门。门上接着珠帘，珠帘后似乎还有一个人坐在那里。
LONG);

	set("type","indoors");
       set("indoors", "wolfmount");
	set("NONPC",1);
	set("exits",([
		"north":__DIR__"grasscabin",
	]) );
	set("item_desc", ([
                "zhulian": "这卷珠帘似乎可以掀开（ｏｐｅｎ）。\n",
                "珠帘": "这卷珠帘似乎可以掀开（ｏｐｅｎ）。\n",
                "curtain": "这卷珠帘似乎可以掀开（ｏｐｅｎ）。\n",	
        ]) );
	set("coor/x",40);
	set("coor/y",-100);
	set("coor/z",40);
	set("objects",([
     		__DIR__"npc/lanlan":1,
     		__DIR__"npc/zhuyun":1,     		
                BOOKS"skill/assassin-hammer_50" : 1,
    	]) ); 
	setup();
}

void init()
{
        add_action("do_open", "open");
}

void close_path()
{
        if( !query("exits/south") ) 
        	return;
        message("vision","珠帘又落了下来，盖住了暗门。\n",this_object() );
        delete("exits/south");
}

int do_open(string arg)
{
	object me;
	me = this_player();
        if( !arg || arg=="" ) 
        	return 0;

        if( arg=="zhulian" || arg =="珠帘" || arg=="curtain" ) 
        {
                write("你掀开珠帘，");
		if( (int) me->query("force_factor") >= 70 )
		{
			write("推开了后面向南的门。\n");
	        	if( !query("exits/south") ) 
	        	{
     				set("exits/south", __DIR__"backroom");
        			call_out("close_path", 15);
			}
			return 1;	
		}
		else
			write("试着推了推后面的门，但没有推开（须70点加力）\n");
		return 1;
	}
		write("你要掀开什么？\n");
		return 1;
}

int valid_leave(object me, string dir)
{
        object ob;
        int i;
        if( dir == "south" && ob=present("zhu yun", this_object()))
		{
			if ( (string)me->query("class") != "wolfmount" 
				&& me->query("quest/quest")!="完颜铁"
				&& me->query("quest/quest")!="完颜钢")
			{
				message_vision("$N对$n喝道：老太爷不许任何人打搅他！！\n", ob,me);
				return notify_fail("朱云挡住了你的去路。\n");
			}
		}
		return 1;
}

void reset(){
        object item;
        ::reset();
      
	if(!present("shuaiyi picture", this_object())){
		item = new(__DIR__"obj/shuaiyitu");
	        if(objectp(item)){
                	item->move(this_object());
                }
        }
        return;
}       