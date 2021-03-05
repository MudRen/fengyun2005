inherit ITEM;

void create()
{
        set_name("铁箱", ({ "iron case","case"}) );
        set_weight(500); 
		set_max_encumbrance(8000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "个");
                set("long", "一个巨大的铁箱。\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }

void init()
{
        add_action("do_open","open");
}


void reset(){

	if (!random(10))	set_temp("been_get",0);

}

int do_open(string arg)
{
        object /*cash,*/map;
        object guard;       
        
	if(arg!="iron case"&&arg!="铁箱"&&arg!="case") return 0;
	else
	{
		if(guard = present("dragon dizi",environment(this_object())))
			if (guard->query("name")=="青龙会弟子")
        		{
        		message_vision("$N对$n喝道：别瞎动，方老板会要你的命！\n", guard, this_player());
        		return 1;
        		}
       		message_vision("$N打开铁箱的盖子...\n",this_player());
        	if(query_temp("been_get"))
                return notify_fail("你打开铁箱，但里面空空如也，什么也没有。\n");
        	set_temp("been_get",1);
    		tell_object(this_player(),"你发现里面有一张地图，你连忙收了起来。\n");
    		this_player()->set_temp("marks/longlife_getmap",1);
			map=new(__DIR__"map");
			map->move(this_player());
			return 1;
	}
}