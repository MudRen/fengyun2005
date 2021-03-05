// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"千年凝露"NOR, ({ "dew drop","dew" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "滴");
            set("material", "water");
            set("long", "一滴滚动着的晶莹露水，据传千年一结，珍贵无比。\n");
			set("real",1);
			set("value",2000);
          }
	::init_item();
}

void init()
{
	call_out("dissolve",60);
}

int dissolve()
{
	object holder,room;
	if(!objectp(holder=environment())) {
		destruct(this_object());
	}
	if(userp(holder))
		room=environment(holder);
	else room=holder;
	message("vision",this_object()->query("name")+"渐渐的蒸腾消失了。\n",room);
	destruct(this_object());
	return 1;
}