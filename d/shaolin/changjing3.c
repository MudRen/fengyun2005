// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	object ob;
        set("short", "藏经阁");
        set("long", @LONG
少林历代多火劫，藏经阁的设计便防火防尘，颇为巧妙，这层存放着历代皇帝
的圣旨和御赐经书，最为贵重的算是大明正统五年御赐的共计六千七百七十七卷的
《涅磐经》了，许多难得一见的佛教经书在这里可以借来阅览。
LONG
        );
        set("exits", ([ 
  		"up"	: __DIR__"changjing4",
  		"down" : __DIR__"changjing2",
	]));
        set("objects", ([
                __DIR__"npc/monk7" : 1,
                __DIR__"npc/monk71": 1,
        ]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",20);
	set("no_fly",1);
	set("no_lu_letter",1);
	setup();
	ob= new(BOOKS"skill/buddhism_200");
	ob->set_amount(2);
	if (!ob->move(this_object()))
		destruct(ob);
}

void shouyu_notify()	{
	object me,ob;
	me = this_player();
	if((ob = present("shaolin monk",this_object())) && REWARD_D->riddle_check(me,"多事之秋") == 3 && REWARD_D->riddle_check(me,"守经楼") == 1)
	{
		message_vision("$N对$n说道：你要看护的经书在楼上，请上楼！！！！！！\n",ob,me);
		me->set_temp("okey_go_level4",1);
	}
	return;
}

int valid_leave(object me,string dir)
{
	object ob, room, figure;
	
	if(userp(me) && dir == "up")
	{
	
	//	check if upstairs already have a user.
		room = find_object(__DIR__"changjing4");
		if (!objectp(room)) room = load_object(__DIR__"changjing4");
		if (room->usr_in())
				return notify_fail("已经有人在楼上守卫了，你还是等下一个轮换吧。\n");
	
		room = find_object(__DIR__"changjing5");
		if (!objectp(room)) room = load_object(__DIR__"changjing5");
		if (room->usr_in())
				return notify_fail("已经有人在楼上守卫了，你还是等下一个轮换吧。\n");
	
		if (ob=present("shaolin monk",this_object()))
		if(me->query_temp("okey_go_level4") && !me->query("vendetta/shaolin")) 
		{
			me->delete_temp("okey_go_level4");
			room = find_object(__DIR__"changjing4");
			if (!objectp(room)) room = load_object(__DIR__"changjing4");
			if (figure = present("mysterious figure", room))
				if (!userp(figure))
					destruct(figure);

		room = find_object(__DIR__"changjing5");
		if (!objectp(room)) room = load_object(__DIR__"changjing5");
			if (figure = present("mysterious figure", room))
				if (!userp(figure))
					destruct(figure);

			return 1;
		}else if (me->query("vendetta/shaolin")>0 && me->query_temp("okey_go_level4")) {
			message_vision("$N定睛一看,对$n道：杀了少林弟子还来护经楼?\n",ob,me);
			return notify_fail("");
			}
		else {
			message_vision("$N对$n道：没有方丈的亲笔手谕不得上楼！\n",ob,me);
			return notify_fail("");
		}
		me->delete_temp("okey_go_level4");

		room = find_object(__DIR__"changjing4");
		if (!objectp(room)) room = load_object(__DIR__"changjing4");

			if (figure = present("mysterious figure", room))
				if (!userp(figure))
					destruct(figure);

		room = find_object(__DIR__"changjing5");
		if (!objectp(room)) room = load_object(__DIR__"changjing5");
			if (figure = present("mysterious figure", room))
				if (!userp(figure))
					destruct(figure);

	}
	return 1;
}

void init(){
	add_action("do_get","get");
}

int do_get(string arg){
	
	object monk, me;
	
	monk = present("shaolin monk");
	if (!monk)	return 0;
	if (!arg)	return 0;	
	if (arg[0..5] == "niepan" || arg == "all"){
		monk->ccommand("stare");
		return 1;
	}
	
	return 0;
}