// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "铁索");
        set("long", @LONG

∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞

LONG
        );
        set("exits", ([ 
  		"south" : __DIR__"xuanyuan",
  		"north" : __DIR__"huangshan",
	]));
        set("outdoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",0);
	set("coor/z",40);
	setup();
}


void init()
{
	object ob;
	if (this_player()->query_kar() < random(30))
	{
		this_player()->move(this_object());
		message_vision("$N脚下一个不稳，从铁索上直摔下去！\n",this_player());
		ob = load_object(__DIR__"kuzhu");
		this_player()->move(ob);
		message("vision", "只听到一声惨叫，" + this_player()->name() + "不知从什么地方重重的摔了下来！\n",
		environment(this_player()), this_player());
		this_player()->unconcious();
	}
	return;
}
