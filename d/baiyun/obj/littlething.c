// book.c

#include <ansi.h>
inherit ITEM;

void create()
{
    int	i;

   string *names = ({
        WHT"贝壳"NOR,YEL"海螺"NOR, BLU"海星"NOR,RED"珊瑚"NOR,
        MAG"小螃蟹"NOR
    });

    i = random(5);
    set_name( names[i], ({ "littlething" }));
    set("unit", "个");
    set_weight(200);
	set("value",0);
    set("long", "这是在海边才能找到的小玩意。\n");                            
	::init_item();
}
