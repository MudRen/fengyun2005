inherit ROOM;

void create()
{
//	object	con,item;

	set("short", "厢房");
	set("long", @LONG
武当弟子休息的地方。最里面靠墙是一排木床，大约有十几个。房子中央是一
张长方形的木桌，上面摆著一只茶壶，几只茶杯。左面靠墙是一只书架，整整齐齐
地摆著许多书籍。其中最引人注目的是掌门石雁新著的[33m掌法入门[32m与[33m剑法入门[32m。右面
墙上则挂著几把长剑。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"wudang3",
	]));
	set("objects", ([ 
		__DIR__"npc/taoist" : 2,
		__DIR__"obj/table" : 1,
		__DIR__"obj/wall" : 1,
		BOOKS"sword_50" : 1,
		BOOKS"unarmed_50" : 1,

	]));
	set("coor/x",50);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void reset()
{
        object 		*inv;
        object 		con, item;
	int		i;	

        ::reset();
        con = present("table", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 5) {
	        for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
        	item = new(__DIR__"obj/teapot");
        	item->move(con);
        	item = new(__DIR__"obj/cup");
        	item->move(con);
        	item = new(__DIR__"obj/cup");
        	item->move(con);
        }
        con = present("wall", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 3) {
	        for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
        	item = new(__DIR__"obj/sword");
        	item->move(con);
	}
/*      con = present("book shelf", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) ==0) {
        	item = new(__DIR__"obj/book");
        	item->move(con);
	} */
}

/*

void init(){
        add_action("do_get", "get");
}


int do_get(string arg)
{
	string 		obj, from;
	object		me, wall, shelf, table, target, taro;

	if(!arg) {
		return notify_fail("你要拿什么？\n");
	}
	if(sscanf(arg, "%s from %s", obj, from)==2 ) {
		if(obj == "all") {
			write("一次拿太多东西会太明显。\n");
			return 1;
		}
		table =  present("table",this_object());
		wall =  present("wall",this_object());
		shelf =  present("shelf",this_object());
		target =  present(from,this_object());
		me = this_player();
		if(target == table || target == wall || target == shelf) {
			taro =  present(obj, target);
			if(taro && random(10) > 4) {
				message_vision("$N趁没人注意的时候，鬼鬼祟祟地拿了点什么，放进怀里！\n", me);
				me->set_temp("marks/偷书", 1); 
			}
		}
	}
	return 0;
}

int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i;

        if( userp(me) && me->query_temp("marks/偷书")) {
                if( dir == "south"  && ob=present("li", this_object())) {
			return notify_fail(ob->name()+"向你喝道：大胆！竟敢在武当偷东西！\n");
                }
        }

        return 1;
}

*/