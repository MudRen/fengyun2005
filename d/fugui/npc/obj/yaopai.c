// yaopai.c

inherit ITEM;

void create()
{
	::init_item();
	
	set_name("腰牌", ({ "yaopai", "yao pai" }) );
	set_weight(70);
	set("yp",1);
	set("long", "一个证明捕快身份的腰牌，办案时可以出示（show）。\n");
	set("unit", "个");
	set("lore",1);
	set("value", 0);
}

void init()
{

        add_action("do_show","show");
}

int do_show(string arg)
{
	object me,ob;
	if( !arg || arg != "yaopai" )
                return notify_fail("你要出示什么？\n");
        
        me = this_player();
        ob = this_object();
        if( me->is_fighting() )
        	return notify_fail("在战斗中出示腰牌没有用，快解决对手再说！\n");
        if( me->is_busy() )
        	return notify_fail("你上一个动作还没有完成，不能臭显。\n");
        message_vision("$N出示一下$n，叫到：“查案了，闲杂人等请配合．．．。”\n", me, ob);
    	environment(me)->show_notify(ob,0);
    	return 1;
}
