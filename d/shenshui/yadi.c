// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "崖底");
        set("long", @LONG
石头是黑色的，浪似乎也是黑色的，浪头打到崖底的石头上溅起朵朵白色的水
花，你用尽力气也挣脱不了浪头的束缚，只感觉到浪底的水流似乎比较平稳。大自
然的力量还是人力所无法抗衡的。
LONG
        );
    set("outdoors","shenshui");
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",-60);
    setup();
}

void init(){
    	if(interactive(this_player())){
        	call_out("do_flush",30,this_player());
    	}
    	add_action("do_dive", "dive");
}

void do_flush(object me)
{
   		object room;
		string nroom;
		int level;
		
    	if(!me || environment(me) != this_object()) {
        		return;
    	}
    	
    	level = F_LEVEL->get_level(me->query("combat_exp"));
    	if (level < 18)	nroom = "ocean0";
    	else if (level < 24) nroom = "ocean1";
    	else if (level < 26) nroom = "ocean2";
    	else nroom = "ocean3";    	        
        room = find_object(__DIR__+ nroom);
        if(!objectp(room)) room= load_object(__DIR__+ nroom );
        me->move(room);
 
}


int do_dive(){
	object me, obj;

	me = this_player();
	message_vision("$N一个猛子扎入了水中。\n", me);
    	obj = find_object(__DIR__"midsea");
    	if(!objectp(obj)) {
        	obj = load_object(__DIR__"midsea");
    	}
    	if (obj->query("underwater") > me->query_skill("swimming",1))
		return notify_fail("你的游泳技能太差，没法过去呀。\n");
    	
    	me->move(obj);
    	message("vision", me->name() + "沉入你身边的水中。\n", environment(me), me);
    	return 1;
}
