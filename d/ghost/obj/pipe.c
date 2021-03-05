// pipe.c

inherit ITEM;

void create()
{
        set_name("铜哨",({ "pipe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "steel");
                set("long", "一根约两寸多长的铜哨。\n");
                set("desc_ext", "blow copper pipe");
        }
	::init_item();
}

void init()
{
        if(environment()==this_player())
        	add_action("do_blow", "blow");
}

int do_blow(string arg)
{
        object ob;
        
        if (!arg)	return 0;
        ob = present(arg, this_player());
        if (!ob || ob!= this_object())	return 0;
        	
        message_vision("$N拿起一个" + this_object()->name() + "吹了一声。\n", this_player() );
        environment(this_player())->pipe_notify();
        return 1;
}
