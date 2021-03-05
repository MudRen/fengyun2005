
inherit ITEM;

void create()
{
        set_name("石棺", ({ "coffin"}) );
        set_weight(50000); 
		set_max_encumbrance(8000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "个");
                set("long", "一个巨大的石棺。\n");
                set("value", 1);
        }
    	::init_item();
}
int is_container() { return 1; }

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object sp;
		if(!arg="coffin"||!arg="石棺") return 0;
        message_vision("$N试着推动石棺的盖子...\n",this_player());
        if(query_temp("been_get"))
                return notify_fail("你推开石棺，但里面空空如也，什么也没有。\n");
        set_temp("been_get",1);
    	tell_object(this_player(),"你发现里面藏着一柄长枪，你把它拿了出来。\n");
    	sp=new(__DIR__"spear");
    	sp->move(this_player());
    	return 1;
}
