inherit ROOM;

void create()
{
	set("short", "翠竹园");

	set("long", @LONG
“有竹无肉轩”四周就是翠竹园，这里种满了竹，每到风清月白的夏夜，富贵
山庄的历代主人们便会来此，一把竹椅，一壶清茶，听那海浪般的竹涛声，可惜王
动很久已经没这个兴致了，倒是会时常和他的兄弟们砍竹卖钱换酒，年复一年，翠
竹园中的竹子也越来越少。
LONG);
	set("outdoors", "fugui");
	set("type","forest");
	set("exits",([
		"north":__DIR__"wuzhuxuan",
	]) );
	
	set("item_desc", ([
                "bamboo": "青青的竹子随风摇摆，你似乎可以折（pick）几根下来。\n",
		"竹子": "青青的竹子随风摇摆，你似乎可以折（pick）几根下来。\n",
        ]) );
	set("coor/x",-10);
	set("coor/y",200);
	set("coor/z",80);
	setup();
}

void init()
{
	add_action("do_pick","pick");
}

do_pick(string arg)
{
	object bamboo;
	if ( !arg && arg != "bamboo" && arg != "竹子" )
		return notify_fail("你要折什么？\n");
	if((int) query("picked") <= 3)
	{
		write("你折了一根青青的竹子，小心的放在怀里。\n");
		bamboo = new("/d/taoyuan/obj/bamboo");
		bamboo->move(this_player());
		add("picked",1);
		return 1;
	}
	else
        write("竹子已经被人折光了！！\n");
        return 1;
}

void reset()
{
	:: reset();
	delete("picked");
}