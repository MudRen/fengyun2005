#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", HIW"天下第一峰"NOR);

	set("long", @LONG
这里便是天下第一峰——珠穆朗玛峰！！
天下群山，远方的大草原尽在脚下。白色的布达拉宫在骄阳下看来亮如纯银，但见
天蓝色的冰川，像彩缎一样，从峰顶向四面八方撒下去，镶嵌在洁白的山坡上。狂
风虽劲，冰雪骇人，但望着这大好山河，豪情在胸，壮志凌云，你顿生睥睨天下之
心，长啸连连，击掌放歌。
LONG);

		set("type","street");
		set("objects", ([
//		__DIR__"npc/champion":1,
        ]) );
        set("exits", ([
        	"return":	"/d/fy/fysquare",
        ]));
        set("no_fly", 1);
        set("outdoors", "guanwai");
		set("coor/x",-50);
		set("coor/y",-100);
		set("coor/z",888);
		setup();
        call_other( "/obj/board/hero_b", "???" );
}



void init()
{
	object me = this_player();
	
	if (!userp(me))	return;
		
	if (!REWARD_D->check_m_success(me,"勇登珠峰")) {
		CHANNEL_D->do_sys_channel("info",sprintf("%s于%s勇登天下第一峰——珠穆朗玛峰！\n",
					me->name(1),NATURE_D->game_time()));
		REWARD_D->riddle_done(me,"勇登珠峰",50,1);
		me->set("Add_force/勇登珠峰",50);
		me->set("Add_mana/勇登珠峰", 50);
		me->set("Add_atman/勇登珠峰",50);
		
		me->add("max_force",50);
		me->add("max_mana",50);
		me->add("max_atman",50);
		
		tell_object(me,WHT"你的内力、法力、灵力都提高了！\n\n"NOR);
	}	
	
	remove_call_out("greeting");
	call_out("greeting",1);
}




void greeting()
{
	object room,me;
	object *olist;
	mixed *local;
	int i,flag=0;
	local = NATURE_D->getTime(time());
	room = this_object();
	if (local[3] == 6 && local[2] == 6)
	{
		olist = all_inventory(room);
		for(i=0; i<sizeof(olist); i++)
			if (olist[i]->query("void") && !userp(olist[i]))
				flag=1;
		if (!flag && query("create_void") < local[4])
		{
			me = new(__DIR__"npc/void");
			me->move(room);
			set("create_void",local[4]);
		}
	}
	else
	{
		olist = all_inventory(room);
		for(i=0; i<sizeof(olist); i++)
			if (olist[i]->query("void") && !userp(olist[i]))
				destruct(olist[i]);
	}
	remove_call_out("greeting");
	call_out("greeting",60);
}
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

int valid_leave(object me, string dir){
	if (userp(me))
		message_vision(WHT"$N放声长啸，御风而去，消失在云间。\n\n"NOR, me);
	return ::valid_leave(me,dir);
}