inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "小院");
        set("long", @LONG
走进这扇门，便是翠浓的香闺。小院子里疏落落的种着几十竿翠竹，衬着角落
里的天竺葵，和一丛淡淡的小黄花，显得清雅而有余韵。这儿是这样地幽静。地上
铺满了绿草、落下来的榆钱和风吹来的柳絮。
LONG
        );
        set("exits", ([ 
		"north": __DIR__"xiaojinku",
		"enter": __DIR__"xiaojinku3",
	]));
        set("objects", ([
        	__DIR__"npc/girl":	1,
	]) );
	set("item_desc", ([
		"flower": "角落里的天竺葵正开的灿烂，让人忍不住想去摘上几朵。(pick)\n",
		"天竺葵": "角落里的天竺葵正开的灿烂，让人忍不住想去摘上几朵。(pick)\n",
	]));
	
        set("coor/x",-40);
        set("coor/y",-15);
        set("coor/z",0);
	set("map","zbwest");
        set("have_herb",5);
	setup();
	create_door("north","door","窄门","south",DOOR_CLOSED);
}

int init(){
        add_action("do_pick","pick");
}


int do_pick(string arg) {
        int num;
        object herb,girl, me = this_player();
        if (arg == "flower" || arg == "天竺葵") {
                if (girl = present("little girl",this_object()))
                	return notify_fail("大眼睛的小姑娘说：“别动，这花儿是翠浓姐姐最喜欢的。”\n");
                if (query("have_herb")) {
                        message_vision("趁没人注意，$N从地上拔了几株天竺葵放入怀中。\n",this_player());
                        add("have_herb",-1);
                        herb = new(__DIR__"obj/flower");
                        if (!herb ->move(me))
                                herb->move(this_object());
                        return 1;
                }        
                 else {
                        tell_object(me, "这儿的天竺葵已经摘完了。\n");
                }
                return 1;
        }
        return notify_fail("你想摘什么？\n");
}

void reset() {
        set("have_herb",1);
        ::reset();
}
