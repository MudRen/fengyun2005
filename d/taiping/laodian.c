inherit ROOM;
void create()
{
        set("short", "平安老店");
        set("long", @LONG
平安老店是个客栈，也是家酒铺。门外挂着一盏风灯，灯笼已残破，虽然是风
灯，也已再经不起大风雨。屋檐下挂着个鸟笼，空的鸟笼。店内本来留有两盏灯，
现在却只剩一盏。窗外夜雨如丝，窗内昏灯如豆。油腻柜台后坐着个老人，怔怔地
看着油灯出神，似乎没有注意到你进来。 
LONG
        );
        set("exits", ([ 
		"east":  __DIR__"mroad4",
	]));
        set("item_desc", ([
 	]));
        set("objects", ([
        	__DIR__"npc/oldowner" : 1,
                        ]) );
	set("coor/x",-30);
	set("coor/y",-30);
	set("coor/z",0);
	set("map","taiping");
	set("cage",1);
	setup();
}

void init(){
	add_action("do_get","get");
	add_action("do_get","pick");
	add_action("do_look","look");
}

int do_look(string arg){
	if (arg=="cage" || arg == "鸟笼" || arg=="niaolong" || arg=="birdcage") {
		if (present("birdcage",this_player())) return 0;
		if (present("birdcage",this_object())) return 0;
		if (!query("cage"))
			tell_object(this_player(),"这儿没有鸟笼。\n");
			else tell_object(this_player(), "一只很普通的鸟笼，笼门半开着，里面空空的什么也没有。\n");
		return 1;
	}
	return 0;
}


int do_get(string arg){
	object birdcage;
	if (arg=="cage" || arg == "鸟笼" || arg=="niaolong" || arg=="birdcage") {
		if (!query("cage"))
			return notify_fail("鸟笼已经被人摘走了。\n");
		message_vision("$N伸手拉了拉屋檐下那只鸟笼，挂着的绳子断了，鸟笼啪地一声落到地上。\n",this_player());
		birdcage=new(AREA_TAIPING"obj/birdcage");
		if (birdcage) birdcage->move(this_object());
		set("cage",0);
	        set("long", @LONG
平安老店是个客栈，也是家酒铺。门外挂着一盏风灯，灯笼已残破，虽然是风
灯，也已再经不起大风雨。屋檐下一根半截长的绳子晃晃荡荡，店内本来留有两盏
灯，现在却只剩一盏。窗外夜雨如丝，窗内昏灯如豆。油腻柜台后坐着个老人，怔
怔地看着油灯出神，似乎没有注意到你进来。 
LONG
        );
        	return 1;
        }
        return 0;
}
		
void reset(){
	::reset();
	 set("long", @LONG
平安老店是个客栈，也是家酒铺。门外挂着一盏风灯，灯笼已残破，虽然是风
灯，也已再经不起大风雨。屋檐下挂着个鸟笼，空的鸟笼。店内本来留有两盏灯，
现在却只剩一盏。窗外夜雨如丝，窗内昏灯如豆。油腻柜台后坐着个老人，怔怔地
看着油灯出神，似乎没有注意到你进来。 
LONG
        );
        set("cage",1);
}

/*
int valid_leave(object me,string dir) {
        object ob,end_room,*inv;
		int i, num;
	
		if( userp(me) && dir == "east" ) {
			num = sizeof(me->query("marks/parrot"));
			
			if ( REWARD_D->riddle_check(me,"喋血鹦鹉")==6 && num >=6
					&& !me->query("marks/parrot/遇刺") ) {
				end_room = find_object(__DIR__"mroad4");
				if(!objectp(end_room)) 
        			end_room = load_object(__DIR__"mroad4"); 
        		message("vision",me->name()+"走了过来。\n",end_room);
        		me->move(end_room);
				message("vision",me->name()+"向东离开。\n",this_object());
				inv=all_inventory(end_room);
				for (i=0;i<sizeof(inv);i++){
					if (inv[i]->query("marks/parrot_killer")){
						message_vision("$N对着$n叫到：明年今日就是你的忌日！！\n",inv[i],me);
						inv[i]->kill_ob(me);
						me->kill_ob(inv[i]);
					}
				}
				return notify_fail("");		
			}
		}
		return 1;
}*/