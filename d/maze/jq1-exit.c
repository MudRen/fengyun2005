// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "宣武堂");
	set("long", @LONG
上官极善用人之道，宣武堂中极尽豪华奢侈，美女佳酿，应有尽有。此时堂中
空无一人，空气中弥漫着一股甜腻的味道，侧耳倾听，内室里传来男女欢笑之声，
从屋顶垂下的挂纱如梦似幻般轻轻的飘动，看不清里面的动静。
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"west" : __DIR__"jq1-maze/exit",
	]));
        set("objects", ([
                __DIR__"npc/jq1-hyguard" : 1,
       	]) );
        
        set("item_desc", ([
        	"挂纱":	"
从屋顶垂下的挂纱如梦似幻般轻轻的飘动，挂纱（pull）下似乎一对男女正在云雨。。\n",
        	"sha":	"
从屋顶垂下的挂纱如梦似幻般轻轻的飘动，挂纱（pull）下似乎一对男女正在云雨。。\n",
	]) );
	setup();
	
}



void 	init(){
	add_action("do_pull","pull");
    	add_action("do_listen","listen");
}

int do_listen(string arg) {
	
	if (!arg) {
		tell_object(this_player(),HIM"\n~~~~~~~~嗯~~~~嗯~~~~~~啊~~啊~~~~~~~~~\n\n"NOR);
	}
	return 1;
}

int	do_pull(string arg){
	
	object me = this_player();
	object room, guard, *inv;
	int i;
	if (me->is_busy())
		return notify_fail("你现在正忙着。\n");
	if (guard = present("yellow sentry",this_object()))
	if (guard->query("attitude")== "aggressive")
		return notify_fail("黄衫卫喝道：“想干什么？”\n");
	if (!arg)	return notify_fail("你想拉什么?\n");
	if (arg == "挂纱" || arg == "sha" || arg=="纱" || arg=="guasha") {
		room = find_object(__DIR__"jq1-end");
		if (!room) room = load_object(__DIR__"jq1-end");
		if (!REWARD_D->riddle_check(me,"初探金钱")|| room->usr_in() )
			return notify_fail("知廉耻之人，怎可轻易扰人好事？\n");
		message_vision(WHT"\n$N走到门边，轻轻一掀轻纱走了进去。 \n\n"NOR,me);
		
		inv = all_inventory(room);
		for (i=0;i<sizeof(inv);i++)
			if (!userp(inv[i]))
			if (inv[i]->query("id")=="lu fengxian" 
				|| inv[i]->query("id")=="meihuadan")
			destruct (inv[i]);
		
		room->reset();
		me ->move(room);
		me->start_busy(5);
		room ->event1(me,0);
		return 1;
	}
	tell_object(me, "这东西没法打开。\n");
	return 1;
}
