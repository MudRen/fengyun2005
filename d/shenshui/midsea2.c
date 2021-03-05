// Silencer @ FY4 workgroup. Aug.2004
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "海水中");
        set("long", @LONG
这儿的水流依然平稳，只是光线弱了许多，迷迷蒙蒙的象笼着一层雾，数尺开
外便是昏沉沉的一片，阴影中似乎有什么在移动。静，令人窒息的寂静，没有波涛，
没有游鱼，你忽然觉得心情沉重起来。
LONG
        );
    	set("exits", ([
        	"up" : __DIR__"midsea",
        	"down":	__DIR__"botsea",
    	]) );
    	set("objects",([
        	__DIR__"npc/octopus":	1,
    	]) );
    	set("no_fly", 1);
		set("coor/x",-10);
		set("coor/y",-30);
		set("coor/z",-80);
		set("no_fly",1);
		set("underwater",100);
		set("water_damage",20);
	   	setup();
}

void init()
{
	object octopus;
	if(userp(this_player())){
		this_player()->apply_condition("underwater",10);
		add_action("do_dive", "dive");
		remove_call_out("attack");
		octopus=present("octopus",this_object());
		if (objectp(octopus))
		{
			message_vision(BLU"昏暗的水中慢慢升起一个巨大的阴影，缓缓向$N移近！！\n\n"NOR,this_player());		
			call_out("attack",1+random(2),this_player(),0);
		}
	}
}


int attack(object me, int count)
{
	object octopus;
	
	if (environment(me)!= this_object())	return 1;
	
	octopus=present("octopus",this_object());
	
//	tell_object(me,"here i am"+ octopus->name()+ " hit you " + count +"\n");
	
	if (!objectp(octopus))	return 1;
	
	if (octopus->is_fighting())	return	1;
		
	
	COMBAT_D->do_attack(octopus,me);

	count++;
	if (count<40)		
		call_out("attack",1+random(2),me,count );
	else
	{
		message_vision(WHT"\n\n大章鱼忽然消失，化作了你熟悉的那个美丽的身影。
		
鲛女轻轻地向你又笑了笑，向下潜去，消失在蔚蓝的海水深处。\n\n"NOR, me);
		destruct(octopus);
	}
	return 1;	
}


int do_dive(){
	object me, obj, room,octopus;
	me = this_player();
	obj = me->query_temp("armor/mask");
	
	if (octopus=present("octopus",this_object()))
		return notify_fail("大章鱼八爪翻飞，挡住了你的去路。\n");
	
	room = find_object(__DIR__"botsea");
	        if(!objectp(room)){
	            room = load_object(__DIR__"botsea");
	        }
	
	if (room->query("underwater") <= me->query_skill("swimming",1)) {
		message_vision("$N继续向下潜去。\n", me);
		if (room->usr_in()) {
			tell_object(me,"下面好像有人，潜不下去耶。\n");
			return 1;
		}  else 
			room->reset();
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
