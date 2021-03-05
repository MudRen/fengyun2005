// bamboo_pipe.c

inherit ITEM;

void create()
{
        set_name("竹管",({ "bamboo pipe", "pipe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("material", "bamboo");
                set("long", "一根约两尺多长的竹管，上面戳了三个小孔，也许可以用来吹奏。\n");
                set("desc_ext", "blow bamboo pipe");
        }
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

        message_vision("$N拿起一根" + name() + "呜嘟嘟地吹了起来。\n",this_player() );
        environment(this_player())->pipe_notify();

        return 1;
}
