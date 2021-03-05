// Copyright (C) Apstone, Inc.
#include <armor.h>
inherit FINGER;
void create()
{
	set_name("定婚戒指", ({ "engagement ring","ring"}) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个镶着个闪闪发光钻石的戒指，你还可以在上面刻字（carve）\n");
		set("unit", "个");
		set("value", 700000);
		set("armor_prop/armor", 0);
		set("wear_msg", "$N轻轻地把一个$n戴在手指上。\n");
		set("unwield_msg", "$N轻轻地把$n从手指上除了下来。\n");


	}
	::init_item();
}
void init()
{
	if(environment()==this_player() && !query("carved"))
	add_action("do_carve","carve");

}
int do_carve(string arg)
{
set("long","一个闪闪发光的定婚钻戒，上面刻着：\n"+
arg+"\n");
set("carved",1);
tell_object(this_player(),"ＯＫ\n");
return 1;
}
