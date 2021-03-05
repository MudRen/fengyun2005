#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"太平灯笼"NOR, ({ "lantern"}) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "cloth");
                set("long", "这是郝生意请巧匠专做的太平灯笼，狼山虽说地远风急，但这灯笼却从不\n熄灭，端是精巧。 \n");
        }
}

void init()
{
        if(this_player()==environment())
        add_action("do_light", "use");
}

int do_light(string arg)
{
        if( arg != "lantern" ) return 0;
        tell_object(this_player(),"你掏出一个" + this_object()->name() + "点亮了灯芯。\n");
        environment(this_player())->light_notify(this_object(), 0);
        return 1;
}
