//	Used by /d/fy/npc/mapseller
// 	熟悉各地描述的工作	--- By silencer@fy4. workgroup

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("空白的卷轴", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","一卷绢册");
                set("value", 1000);
				set("destination","none");
				set("room_name", "天机广场");
				set("usage", "map");
				set("material", "paper");
        }
        ::init_item();
}


void init()
{
   	add_action("do_record","record");
   	add_action("do_look", "look");
}
    
int do_record(string arg)
{
    	object me;
	string desc;
    	    
    	me = this_player();
	
	if (query("room_desc"))
		return notify_fail("卷轴上已经有内容了。\n");

	if ( (file_name(environment(me))+ ".c") != query("destination")) {
		if (environment(me)->query("short") == query("room_name"))
			write("好像就是在这儿了，在周围转转吧，也许地名有重复。\n");
		else
			write("这儿不是你要考察的地方。\n");
		return 1;
	}
		
	message("vision", me->name() + "抬头看了看四周，埋头"
                "仔仔细细的绘制着什么。\n", environment(me), ({ me }));
        tell_object(me, "你精心的绘制了" + query("room_name") + "附近的地形。\n");
        set("name","绘制完的卷轴");
        set("value",0);
        if (stringp (desc = environment(me)->query("long")))
        	set("room_desc", desc);
        
    	return 1;
}

int do_look(string arg) {
	string msg;
	
	if (arg == "scroll" || arg == "卷轴") {
		if (query("destination") == "none")
			msg = YEL"一卷空白的绢册，把它给徐万里，他会替你安排行程。\n"NOR;
		else {
			msg = YEL"\n一卷绢册，抬头写着："NOR + query("area") + "  " + query("room_name") + "\n";
			if (query("room_desc")) {
				msg += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				msg += "    "+query("room_desc");
				msg += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			} else
				msg += YEL"请到上述地点纪录周围的风土人情（record）。\n"NOR;
		}
		write(msg);
		return 1;
	}
	return 0;
}
