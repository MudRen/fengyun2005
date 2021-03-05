inherit ROOM;

void create()
{
	set("short", "花丛中");

	set("long", @LONG
四处都是花，这里简直就是花的海洋，四下静悄悄，异常安静。地上干干净净
的，一尘不染。四周是半人高的竹篱笆，在百花掩映中，一扇小门关得紧紧的。
LONG);

	set("type","house");
	set("exits",([
		"northdown":__DIR__"cloudedge",
	]) );
        set("objects", ([
                __DIR__"obj/huacong" : 1,
       ]) );
	set("coor/x",40);
	set("coor/y",-80);
	set("coor/z",40);
       set("outdoors", "wolfmount");
        set("item_desc", ([
                "小门": "一扇竹门紧紧关着。\n",
                "door": "一扇竹门紧紧关着。\n",
        ]) );

	setup();
}

void init()
{
	object me;
	me = this_player();
	if( me->query("marks/wolf_pass_oldman") )
	{
		add_action("do_knock","knock");
	}
}

int closepath()
{
        if( !query("exits/enter") ) 
        	return 1;
        message("vision","小门又无声无息的合上了。\n",this_object());
		delete("exits/enter");
	return 1;
}

int do_knock()
{
	add("num",1);
	if(!((int) query("num") % 3))
	{
		if( !query("exits/enter"))
		{
			set("exits/enter",__DIR__"grasscabin");
			message("vision","＂吱啦＂一声，小门自动向里打开。\n",this_object());
			call_out("closepath",5);
			return 1;
		}
	}
	else
	{
		message_vision("$N轻轻的敲敲小门。\n",this_player());
		return 1;
	}
	return 0;
}

void reset()
{
	::reset();
	delete("num");
}
