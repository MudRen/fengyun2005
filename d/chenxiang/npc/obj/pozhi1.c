inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("破纸片", ({ "paper"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "一张破纸片，你依稀可以辨认出“。。黄。。土坡。。“三字。\n");
		set("value", 1);
	}
}



