inherit ITEM;

void create()
{
	::init_item();
	
	set_name("神教令牌", ({ "yaopai", "yao pai" }) );
	set_weight(70);
	set("yp",1);
	set("long", "一个西方神教堂主佩戴的令牌，可以出示（show）。\n");
	set("unit", "个");
	set("value", 0);
}

void init()
{
        if (environment(this_object()) == this_player())
        	add_action("do_show","show");
}

int do_show(string arg)
{
	object me,ob;
	if( !arg || arg != "yaopai" )
                return notify_fail("你要出示什么？\n");
        
        me = this_player();
        ob = this_object();
        if(me->is_fighting() )
        	return notify_fail("在战斗中出示令牌没有用，快解决对手再说！\n");
        if(me->is_busy() )
        	return notify_fail("你上一个动作还没有完成。\n");
        message_vision("$N出示一下$n，叫到：“西方神教，文成武德，千秋万载，一统江湖。”\n", me, ob);
    	return 1;
}
