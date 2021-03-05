
inherit ITEM;
void create()
{
	set_name("蒲昌小扇子" , ({ "little fan" , "fan"}) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个十分精致的蒲昌小扇子，上面还带着淡淡的香气。\n");
		set("value", 2000);
		set("holiday", "鬼节");
	}
	::init_item();
}

void init(){
	add_action("do_use", "use");
}

int do_use(string arg){
	object me;
	int i;
	me = this_player();
	if(!arg || (arg != "little fan" && arg != "fan")){
		return 0;
	}
	if(me->is_busy() || me->is_fighting()){
		return notify_fail("你正在忙！\n");
	}
	i = NATURE_D->get_season();
	if(i == 2){
		message_vision("$N拿出蒲昌小扇子轻轻的摇着，空气中漂浮着淡淡的香气。\n", me);
		tell_object(me, "你只觉得一阵清凉的微风拂过，暑气顿消。\n");
	} else if( i == 4) {
		message_vision("$N一边哆嗦着一边摇着蒲昌小扇子。\n", me);
		tell_object(me, "哇。。好冷呀！\n");
	} else {
		message_vision("$N拿出蒲昌小扇子轻轻的摇着，空气中漂浮着淡淡的香气。\n", me);
	}
	return 1;
}
