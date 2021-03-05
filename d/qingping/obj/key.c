//XXDER
inherit ITEM;
void create()
{
        set_name("钥匙", ({ "key", "钥匙"}) );
		set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把长长的但生了锈的钥匙。\n");
                set("desc_ext","use key");
                set("value", 50);
        }
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        if( arg != "key" && arg != "钥匙") return 0;

        tell_object(this_player(),"你掏出一个" + this_object()->name() + "。\n");
        environment(this_player())->key_notify(this_object(), 0);

        return 1;
}
