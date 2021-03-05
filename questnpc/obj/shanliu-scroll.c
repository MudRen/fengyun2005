#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(GRN"山流书"NOR, ({ "shanliu-shu"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("value", 0);
                set("long",
"这是现今江湖上以悲天悯人救苍生为宗旨的“山流”致以武林名侠们的密函，为了\n度过黑道群魔再起之劫，山流致天下以山流书，邀天下豪侠共商灭天宗之事。\n"NOR);
        }
	::init_item();
}

