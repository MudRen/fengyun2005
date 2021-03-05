#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "三清宫");
	set("long", @LONG
两扇铜钉大门紧紧关着，门的上方挂着一块金匾，匾上龙飞凤舞地写着＂三清
宫＂三个大字。门的两侧各有一座铜狮。使人感到庄严的气份笼罩着这个地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"south" : __DIR__"grassland2",
]));
        set("item_desc", ([
                "door": "铜钉的大门，门上有门环，你可以敲(knock)门。\n",
                "门": "铜钉的大门，门上有门环，你可以敲(knock)门。\n",
        ]) );
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}

void init()
{
//    	add_action("do_break", "break");
       	add_action("do_knock", "knock");
}

void wantopen(object me)
{
	object	waiter, tao1, tao2, tao3;
	object	room;


	seteuid(geteuid());
	room = find_object(__DIR__"da_yuan");

	message("vision", "\n吱的一声，门向里开了。\n", this_object());
    if(present("taoist fighter", this_object())){
    	return;
    }
   	waiter = new(__DIR__"npc/waiter_taoist");
    message("vision", waiter->name()+ "走了过来。\n", this_object());
	if( room )  message("vision", waiter->name() + "吱的一声把门打开，走了出去。\n", room);
	waiter->move(this_object());
	message("vision", "孙天灭说道：这位"+ RANK_D->query_respect(me) + 
		"请进。\n", this_object());
	call_out("closedoor", 10, me);
}

int do_knock(string arg)
{
	object room, me, thisroom;

        if( arg=="door" || arg == "门") {
		me = this_player();
		if(query("exits/north")) {
			message_vision(HIB "门是开着的，敲什么？\n"NOR, me);
			return 1;
		}
		message_vision(HIB "$N走到门前，轻轻地用门环敲了两下。\n"NOR, me);
		set("long", @LONG
铜钉大门敞开着，门的上方挂着一块金匾，匾上龙飞凤舞地写着＂三清宫＂
三个大字。门的两侧各有一座铜狮。使人感到庄严的气份笼罩着这个地方。
LONG
	);
		set("exits/north", __DIR__"da_yuan");
	        if( room = find_object(__DIR__"da_yuan") ) {
			message("vision", HIB "你听到当当两声，有人在门外敲门。\n"NOR, room);
			room->set("exits/south", __FILE__);
			room->set("item_desc", ([
                		"door": "铜钉的大门，门是开着的。\n",
                		"门": "铜钉的大门，门是开着的。\n",
        		]) );
		}
		me->start_busy(2);
		call_out("wantopen", 2, me);
		
        }
	else {
		write("你要敲什么？\n");
	}
                return 1;
}

void closedoor(object me)
{
	object obj, room, troom;

	troom = this_object();
        
        room = find_object(__DIR__"da_yuan");			
		obj = present("fighter", troom);
		if(obj) {
			message("vision", obj->name() + "走进道观，轻轻地把门关上了。\n", troom);
			destruct(obj); 
		}
		
		if(room) {
			room->delete("exits/south");
			room->set("item_desc", ([
               	"door": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
               	"门": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
        			]) );
			tell_room(room,"大门又关上了。\n");
		}
		delete("exits/north");
		set("long", @LONG
两扇铜钉大门紧紧关着，门的上方挂着一块金匾，匾上龙飞凤舞地写着＂三
清宫＂三个大字。门的两侧各有一座铜狮。使人感到庄严的气份笼罩着这个地方。
LONG
	);
		return;
}


void reset(){
	object room;
	::reset();
	if(query("exits/north")){
		set("long", @LONG
两扇铜钉大门紧紧关着，门的上方挂着一块金匾，匾上龙飞凤舞地写着＂三
清宫＂三个大字。门的两侧各有一座铜狮。使人感到庄严的气份笼罩着这个地方。
LONG
		);	
		room = find_object(__DIR__"da_yuan");
		if(objectp(room) && room->query("exits/south")){
			room->delete("exits/south");
		}
		delete("exits/north");
	}
}
