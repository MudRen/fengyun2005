
inherit ITEM;

void create()
{
	set_name("钓鱼杆", ({ "fish pole" , "pole", "钓鱼杆"}) );
	set_weight(400);
    set_max_encumbrance(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("prep", "on");
		set("long", "一个用竹子做成的钓鱼杆，竹子通体碧绿十分好看。 \n");
		set("value", 150);
	}
    ::init_item();
}

void init()
{
        add_action("do_use", "fishing");
}

int do_use(string arg){
	object me;
	me = this_player();
	if(me->is_busy() || me->is_fighting()){
		return notify_fail("你现在正在忙！\n");
	}
    tell_object(me,"你掏出一个" + this_object()->name() + "。\n");
    environment(me)->fish_notify(this_object());

    return 1;
}

int is_container() { return 1; }

