#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "船头");
        set("long", @LONG
此船船身甚大，皆用红杉木打成，船高二层，与周围的破旧渔船不可同日而语，
船尾一面黑旗在风中猎猎作响，旗上绣着一条张牙舞爪的白龙。舱门紧闭，内里隐
隐传出淫狎的笑声。船头站着数个手持钢刀的蓝衣汉子，个个满脸横肉，显然不是
善类。船舷上一块三米长的跳板通向岸边。
LONG
        );
        set("exits", ([ 
		"enter" : __DIR__"boatcabin",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    "跳板" : "木板很结实，顺着它可以回到(walkto)岸边(bank)。\n",
		    "plank" : "木板很结实，顺着它可以回到(walkto)岸边(bank)。\n",	
	]));
        set("objects", ([
        	AREA_TAIPING"npc/blueman" : 2,
                       ]) );

	set("coor/x",1030);
	set("coor/y",20);
	set("coor/z",10);
	setup();
}


void init()
{
    add_action("do_walk", "walkto");
    add_action("do_listen","listen");
}


int do_listen(string arg) {
	
	if (!arg || arg== "船舱" || arg == "舱门") {
		tell_object(this_player(),MAG"\n~~~~~~~~嗯~~~~嗯~~~~~~啊~~啊~~~~~~~~~\n\n"NOR);
	}
	return 1;
}
	
int do_walk( string arg )
{
	 object me,room;
	 me = this_player();
	 if(!arg || (arg != "bank" && arg != "岸边"))	  	return notify_fail("你要往哪儿走？\n");
	 
	 if (me->query_temp("taiping/walk_plunk_2"))	 	return notify_fail("你已经在跳板上了。\n");
	 if (this_player()->is_busy())	 	return notify_fail("你现在正忙。\n");
	 message_vision("$N沿着跳板走向岸边，木板很结实，像是走在平路上。\n",me);
	 me->set_temp("taiping/walk_plunk_2",1);
	 me->start_busy(3);
	 call_out("do_arrive",6,me);
	 return 1;
}

int do_arrive(object me) {
	object room;
	
	 if (!objectp(me) || me->is_ghost()) return 1;	
	 room = find_object(__DIR__"cape");
         if(!objectp(room))
                 room = load_object(__DIR__"cape");
         message("vision",me->name()+"从跳板上走了过来。\n",room);
         tell_object(me,"你走上了岸边。\n");
         me->move(room);
         me->delete_temp("taiping/walk_plunk_2");
         return 1;
}

int valid_leave(object me,string dir)
{
	object ob;
	if(userp(me) && dir == "enter" && ob=present("blue cloth man",this_object())) {
		if (!me->query_temp("taiping/boat_enter"))	{
			message_vision(ob->name()+"说：龙王还未起身，现在不见客。\n",me);
			return notify_fail("");
		} 
	}
	return 1;
}