inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "洞底");
        set("long", @LONG
你隐约能听到有人愤怒的惊呼声。声音很短促，然后一切又归于平静。但平静
并不代表安全，黑暗中仍然到处都潜伏着危险！ 你发觉右边是一扇门（rightdoor）。
有笑声从门后发出来的，笑声突然变成了令人心跳的呻吟声。声音妖媚而诱惑，简
直令人无法拒绝。你再向左移动，又找着另一扇门（leftdoor）。这扇门后没有声音。
LONG
        );
        set("objects", ([
        __DIR__"npc/bianfu": 1,
                        ]) );
        set("item_desc", ([
                "rightdoor": "你虽然什么也看不见，但心跳已经加快了...\n",
                "leftdoor": "这门和右边那扇一模一样。\n",
        ]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        int i;
        int damage;
        object me,room;
        if(!arg || arg=="")
        {
        	write("你要打开什么？\n");
            return 1;
        }
        if( arg == "leftdoor" ) {
	        me = this_player();
//	这里，让Ppl 逃避血蝙蝠，可能出现一些跳跃的问题，不过，不是call_out问题不大
/*	        if (me->is_busy() || me->is_fighting()){
	        	tell_object(me,"你现在正忙。\n");
	        	return 1;
	        }*/
	        message_vision(HIR"$N刚一推开门，一阵冷箭以快得不能再快的速度射了出来。\n"NOR,me);
			me->receive_wound("kee",random(1000)+150);
			me->set_temp("last_damage_from","在蝙蝠岛中冷箭而死。\n");
			COMBAT_D->report_status(me,1);
	        return 1;
        }
        if( arg == "rightdoor") {
            me = this_player();
/*            if (me->is_busy() || me->is_fighting()){
	        	tell_object(me,"你现在正忙。\n");
	        	return 1;
	        }*/
            tell_object(me,HIR"你刚一推开门，就有一个人投入你的怀抱，将你拉了过去！ \n"NOR);
            message("vision",HIR""+me->name()+"刚一推开门，就有一个人投入"+me->name()+"的怀抱，将"+me->name()+"拉了过去！ \n"NOR,environment(me),me);
			room =load_object(__DIR__"room1");
			me->move(room);
            return 1;
       } 
}

