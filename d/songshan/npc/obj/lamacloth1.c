#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
    set_name(RED"深红僧袍"NOR, ({ "red cloth","cloth" }) );
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("material", "cloth");
        set("long", "这是一件喇嘛穿的红袍。\n");
        set("armor_prop/armor", 10);
    	set("value",400);
    }
    ::init_cloth();
}
