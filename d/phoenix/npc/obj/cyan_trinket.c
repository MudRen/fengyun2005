#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("九玄天魔令", ({ "wood" }) );
	set_weight(500);
	set("no_get",1);
	set("no_drop",1);
	set("no_sell",1);
	set("lore",1);
	set("long","此乃西方神教天魔坛的信物，这一块天魔令上雕著的是一对盘旋交绕的凤凰。");
	set("desc_ext","证实身份");
    ::init_item();
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
