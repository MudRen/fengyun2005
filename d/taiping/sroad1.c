#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "红巷尽头");
        set("long", @LONG
小巷不长，尽头有一扇红门，红门后有一座鹦鹉楼。过往太平镇的，没有不知
道这扇红门和红门后的姑娘的。远远近近，老老少少，多少人在这里花光了平生的
积蓄，可是走出鹦鹉楼后从来就没有人后悔过。小巷南首还有一幢二层小楼，楼下
的黑门紧紧地关着。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"sroad2",
//		"west" : __DIR__"yard",
//		"south": __DIR__"songhouse",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        "door": "一扇红门，一扇黑门。\n",
	        "红门" : "鲜红的门，红如血，门里就是鹦鹉楼。\n",
        	"red door" : "鲜红的门，红如血，门里就是鹦鹉楼。\n",
        	"黑门": "漆黑的门，阳光下完全不见光泽。那种黑色，是一种死黑色，已不像人间所有。门
上雕刻着奇怪花纹，虽然看得很清楚，却仍看不出那是什么东西。据说，那种奇怪
的花纹只是象征着某种难言的不祥与邪恶。\n",
		"black door": "漆黑的门，阳光下完全不见光泽。那种黑色，是一种死黑色，已不像人间所有。门
上雕刻着奇怪花纹，虽然看得很清楚，却仍看不出那是什么东西。据说，那种奇怪
的花纹只是象征着某种难言的不祥与邪恶。\n",
	]));
	set("coor/x",-60);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

void init()
{
       	add_action("do_knock", "knock");
        add_action("do_open", "open");
        add_action("do_push", "push");
        if(query("exits/south")) {
	        set("item_desc", ([
	               	"door": "一扇红门，一扇黑门。\n",
		        "红门" : "鲜红的门，红如血，门里就是鹦鹉楼。\n",
	        	"red door" : "鲜红的门，红如血，门里就是鹦鹉楼。\n",
	                "black door": "漆黑的门，阳光下完全不见光泽。门开着。\n",
	                "黑门": "漆黑的门，阳光下完全不见光泽。门开着。\n",
	        ]) );
	}
	else {
	        set("item_desc", ([
        	"door": "一扇红门，一扇黑门。\n",
	        "红门" : "鲜红的门，红如血，门里就是鹦鹉楼。\n",
        	"red door" : "鲜红的门，红如血，门里就是鹦鹉楼。\n",
        	"黑门": "漆黑的门，阳光下完全不见光泽。那种黑色，是一种死黑色，已不像人间所有。门
上雕刻着奇怪花纹，虽然看得很清楚，却仍看不出那是什么东西。据说，那种奇怪
的花纹只是象征着某种难言的不祥与邪恶。\n",
		"black door": "漆黑的门，阳光下完全不见光泽。那种黑色，是一种死黑色，已不像人间所有。门
上雕刻着奇怪花纹，虽然看得很清楚，却仍看不出那是什么东西。据说，那种奇怪
的花纹只是象征着某种难言的不祥与邪恶。\n",
	        ]) );
	}
	
}


int do_open(string arg)
{
	if (arg=="door" || arg == "门" || arg=="black door" || arg == "黑门"
		|| arg=="red door" || arg == "红门") {
			tell_object(this_player(),WHT "门关着，也许可以试着推一推。\n"NOR);
			return 1;
		}	
	return 0;
}

int do_knock(string arg)
{
	object room, me, thisroom;
	
	me = this_player();
        if( arg=="door" || arg == "门") {
	 	tell_object(me,"你要敲那一扇门？\n");
	 	return 1;
	}
	if (arg=="black door" || arg == "黑门") {
		if(query("exits/south")) {
			tell_object(me,HIB "门是开着的，敲什么？\n"NOR);
			return 1;
		}
		message_vision(HIB"$N走到门前，轻轻地用门环敲了两下。\n"NOR,me);
		message_vision(HIB"黑门里一点动静也没有。\n"NOR,me);
		return 1;
	}
	if (arg=="red door" || arg == "红门"){
		if(query("exits/west")) {
			tell_object(me,WHT "门是开着的，敲什么？\n"NOR);
			return 1;
		}
		message_vision(RED "$N走到红门前，轻轻地用门环敲了两下。\n"NOR, me);
		set("exits/west", __DIR__"yard");
	        room = find_object(__DIR__"yard");
	        if (!room) room=load_object(__DIR__"yard");
	        message("vision", RED"你听到当当两声，有人在门外敲门。\n"NOR, room);
		room->set("exits/east", __DIR__"sroad1");
		me->start_busy(2);
		call_out("wantopen", 1, me);
		return 1;	
        }
	tell_object(me, "你要敲什么？\n");
	return 1;
}

void wantopen(object me)
{
	object	girl;
	object	room;

	seteuid(geteuid());
	room = find_object(__DIR__"yard");
	message("vision", "\n吱的一声，红门向里打开了。\n", this_object());
    	if(present("redgirl", this_object())){
    		return;
    	}
   	girl = new(__DIR__"npc/redgirl");
    	message("vision", girl->name()+ "走了过来。\n", this_object());
	if(room)  
		message("vision", girl->name() + "吱的一声把门打开，走了出去。\n", room);
	girl->move(this_object());
	message("vision", girl->name()+"说道：这位"+ RANK_D->query_respect(me) + 
		"请进。\n", this_object());
	call_out("closedoor", 10, me);
}


void closedoor(object me)
{
	object obj, room, troom;

	troom = this_object();
	if(me && environment(me) != troom) {
	    room = find_object(__DIR__"yard");
		obj = present("redgirl", troom);
		if(obj) {
			message("vision", obj->name() + "走进红门，轻轻地把门关上了。\n", troom);
			destruct(obj); 
		}
		if(room) {
			room->delete("exits/east");
			room->set("item_desc", ([
                	"door": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
                	"门": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
        		]) );
			message("vision", RED"红门又被关上了。\n"NOR, room);
			delete("exits/west");
		}
	} else {
		call_out("closedoor", 15, me);
	}
}

int do_push(string arg)
{
        object room, me;
        me=this_player();
        
        if(arg == "门" || arg =="door" ) {
        	tell_object(me,"你要推哪一扇门？\n");
        	return 1;
        }
        if( arg=="red door"|| arg == "红门") {
        	if(query("exits/west")) {
			tell_object(me,RED "门是开着的，推什么？\n"NOR);
			return 1;
		}
        	
        	tell_object(me,"你用力推了推，红门纹丝不动。\n");
        	return 1;
        }
        if( arg=="black door" || arg == "黑门") {
                me = this_player();
                if(query("exits/south")) {
                        write("黑门是开着的！\n");
		}
		else {
	                set("exits/south", __DIR__"songhouse");
		        set("item_desc", ([
	                "door": "一扇红门，一扇黑门。\n",
	        	"红门" : "鲜红的门，红如血，门里就是鹦鹉楼。\n",
        		"red door" : "鲜红的门，红如血，门里就是鹦鹉楼。\n",
	                "black door": "漆黑的门，阳光下完全不见光泽。门开着。\n",
	                "黑门": "漆黑的门，阳光下完全不见光泽。门开着。\n",
	       		 ]) );
                	message_vision("$N用力一推，黑门吱呀一声打开了。\n", me);
                	if( room = find_object(__DIR__"songhouse") ) {
	                        message("vision", "黑门被人从外面推开了。\n", room);
		                room->set("exits/north", __FILE__);
				call_out("closebdoor", 5, room);
                	}
		}
	}
	else {
                 write("你要推什么？\n");
	}
	return 1;
}



int closebdoor(object room)
{
	message("vision", "黑门又被关上了。\n", room);
	message("vision", "黑门又被关上了。\n", this_object());
        set("item_desc", ([
        	"door": "一扇红门，一扇黑门。\n",
	        "红门" : "鲜红的门，红如血，门里就是鹦鹉楼。\n",
        	"red door" : "鲜红的门，红如血，门里就是鹦鹉楼。\n",
        	"黑门": "漆黑的门，阳光下完全不见光泽。那种黑色，是一种死黑色，已不像人间所有。门
上雕刻着奇怪花纹，虽然看得很清楚，却仍看不出那是什么东西。据说，那种奇怪
的花纹只是象征着某种难言的不祥与邪恶。\n",
		"black door": "漆黑的门，阳光下完全不见光泽。那种黑色，是一种死黑色，已不像人间所有。门
上雕刻着奇怪花纹，虽然看得很清楚，却仍看不出那是什么东西。据说，那种奇怪
的花纹只是象征着某种难言的不祥与邪恶。\n",
        ]) );
	room->delete("exits/north");
	room->set("item_desc", ([
               	"door": "黑色的木板门，门是关着的，你可以拉(pull)门。\n",
               	"门": "黑色的木板门，门是关着的，你可以拉(pull)门。\n",
        ]) );
	delete("exits/south");
}


void reset(){
	object room;
	::reset();
	if(query("exits/west")){
		room = find_object(__DIR__"yard");
		if(objectp(room) && room->query("exits/east")){
			room->delete("exits/east");
		}
		delete("exits/west");
	}
	if(query("exits/south")){
		room = find_object(__DIR__"songhouse");
		if(objectp(room) && room->query("exits/north")){
			room->delete("exits/north");
		}
		delete("exits/south");
	}
}