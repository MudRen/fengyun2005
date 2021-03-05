#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"玉璧"NOR, ({ "jade piece","jade" }) );
    set_weight(10);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "块");
	set("material", "stone");
	set("item_owner","沈浪");
	set("long", "一块普通的玉璧，玉质虽精美，倒也没什么特别之处，
上面刻着“沈浪”二字。\n");
    }
    ::init_item();
}
