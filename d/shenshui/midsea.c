// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;

int room_check(object room);

void create()
{
        set("short", "海水中");
        set("long", @LONG
水流平稳了许多，这里的水呈半透明的蔚蓝色，令人很难想象水面上恶浪滔天
的情景。水在你身边温柔的流动，不时游过的小鱼在你身旁擦身而过，似乎对你的
存在无动于衷。
LONG
        );
    	set("exits", ([
        	"up" : __DIR__"yadi",
        	"down":	__DIR__"botsea",
    	]) );
    	set("objects",([
        	__DIR__"npc/jiaonv":	1,
    	]) );
    	set("no_fly", 1);
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",-70);
	set("underwater",100);
	set("water_damage",20);
    	setup();
}


void init(){
    	
    	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
    	add_action("do_dive", "dive");
    	add_action("do_smile","smile");
}


int do_dive(){
	object me, obj, room, octopus, jiaonv;
	
	me = this_player();
	obj = me->query_temp("armor/mask");
	
	if (jiaonv = present("jiao nu",this_object()))
		return notify_fail("鲛女在水中畅游，挡住了你的去路。\n");
	
	room = find_object(__DIR__"midsea2");
	        if(!objectp(room)){
	            room = load_object(__DIR__"midsea2");
	        }
	
	if (room->query("underwater") <= me->query_skill("swimming",1)) {
		message_vision("$N继续向下潜去。\n", me);
		if (room->usr_in()) {
			tell_object(me,"下面好像有人，潜不下去耶。\n");
			return 1;
		}  else 
			{
				if (objectp(octopus=present("octopus", room)))
					destruct(octopus);
				room->reset();
			}
		me->move(room);
	        this_object()->reset();
	        message("vision", me->name() + "潜到你身边的水中。\n", environment(me), me);
	} else {
	    	return notify_fail("你的游泳技能太差，没法潜下去呀。\n");
    	}
    	return 1;
}

int valid_leave(object me,string dir){
    	
    	if (dir=="down"){
    		tell_object(me,"水流湍急，你得使劲潜（ｄｉｖｅ）下去才行。\n");
    		return notify_fail("");
    	}
    	return 1;
}

int do_smile()
{
	object jiaonv;
		
	add("num",1);
	if(!((int) query("num") % 5))
	if(objectp(jiaonv= present("jiao nu", this_object())))
	{
		message_vision(WHT"\n$n回过头来向$N笑笑，又招招手，一转身潜入海水中不见了。\n\n"NOR,
			this_player(), jiaonv);
		this_player()->set_temp("riddle/碧海蓝心/鲛人一笑",1);
		destruct(jiaonv);
		return 1;
	}
		return 0;
		
}