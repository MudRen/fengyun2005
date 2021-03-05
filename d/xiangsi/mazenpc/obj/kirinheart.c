// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"麒麟心"NOR, ({ "kirin heart","heart" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "粒");
            set("material", "ice");
            set("long", "一粒极其罕见的麒麟心。\n");
			set("real",1);
			set("value",1000);
			set("lore",1);
          }
	::init_item();
}
