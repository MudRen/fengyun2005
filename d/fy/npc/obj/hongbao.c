inherit ITEM;
#include <ansi.h>
void create()
{
    int i;
    string *names = ({
        	RED"红信封"NOR,	WHT"白信封"NOR,	BLU"蓝信封"NOR,	YEL"黄信封"NOR,
    });
	
    	i = random(4);
    	set_name( names[i], ({ "envelope" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long", "一封金狮镖局镖头的家信。\n");
		set("value", 1000);
	}
}



