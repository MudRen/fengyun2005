
inherit ITEM;

void create()
{
	set_name("一具枯乾的骸骨", ({ "skeleton" , "骸骨"}) );
	set_weight(400000);
	set_max_encumbrance(500000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
		set("long", "一具枯乾的骸骨。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


int init_spawn()
{
	object too, room, sand;
	string room_name;
	
	too = new(__DIR__"budda-tooth");
    too->move(this_object());
	
	room_name = AREA_QUICKSAND+"desert"+ (string)random(10);
	
	room = find_object(room_name);
	if (!room)
		room = load_object(room_name);
	if (!room)
		return 0;
	move (room);
	sand = present("sand", room);
	if (sand)	move(sand);
		else destruct();
/*	CHANNEL_D->do_sys_channel(
                   "sys",sprintf("舍利子被分布到%s了，大家快抢啊！！！\n",
                room_name));*/
	return 1;
}

