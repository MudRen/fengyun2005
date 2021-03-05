inherit ITEM;

void create()
{
    set_name("藤萝段", ({"tengluo", "vine", "teng luo"}) );
    set_weight(500);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
        set_default_object(__FILE__);
    else
    {
        set("unit", "根");
        set("long", @LONG
这是一段紫色的藤萝，藤萝的皮柔韧而结实，可以做一条很长的绳子。（ｍａｋｅ）
LONG
            );
        set("value", 0);
    }
    ::init_item();
}

int do_make(string arg)
{
    object ob;
    object me=this_player();
    message_vision("$N用灵活的手指剥下了藤萝的皮，三下两下搓成了一条长绳。\n",
                   me);
    ob=new(__DIR__"brope");
    ob->move(me);
    destruct(this_object());
    return 1;
}

void init()
{
    add_action("do_make","make");
}


