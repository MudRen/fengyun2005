#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("青铜钥匙", ({ "key" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 0);
		set("material", "jade");
        set("long", "一柄结着铜锈的青铜钥匙，看来不是新近打造的，不知可以用在（Use key）哪扇门上？。\n");
	}
    ::init_item();
}

void init()
{
        add_action("do_open", "use");
}

int do_open(string arg)
{
	object obj, room, room1;
	object *team;
	int i;
	if (arg == "key" || arg == "青铜钥匙" || arg = "钥匙") {
	if (environment(this_object())!=this_player() || !arg)
		return 0;
	if (!objectp(obj=present("iron door",environment(this_player()))))
		return notify_fail("在这里你打不开什么门。\n");
	message_vision(YEL"$N把钥匙插到锁孔中一转，吱呀一声，白玉小门打开了，石壁上露
出一条通道，白玉钥匙却折断在锁孔里。\n"NOR, this_player());
	room1 = find_object(AREA_EREN2"jailroad5");
        if(!objectp(room1)) 
        	room1 = load_object(AREA_EREN2"jailroad5");   
	room1->set("exits/north",AREA_EREN2"mouseroom1");
	destruct(this_object());
	}
	return 1;
}
