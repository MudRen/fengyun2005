inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "密林");
        set("long", @LONG
密林里一片漆黑，绝无树叶触擦的声音，也绝无夏夜的那种半明半昧的清光。
高大的树干狰狞张舞。枯萎丛杂的矮树在林边隙地上瑟瑟作声。长大的野草在寒风
中鳗鲡似地蠕蠕游动。蓁莽屈曲招展，有如伸出了长臂，张爪攫人。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"forest2",
		"southeast":	__DIR__"forest4",
	]));
        set("item_desc", ([
        	"tree": "高大的树木，没有一定的功夫看来很难爬上去。\n",
		"树干": "高大的树木，没有一定的功夫看来很难爬上去。\n",
		"树":   "高大的树木，没有一定的功夫看来很难爬上去。\n",
		"矮树": "茂密的矮树丛在地上交织错生，使人几乎迈不开脚步。你仔细俯下身一看，
树丛中隐藏着两条黑色的藤蔓，一头铺在地上，另一头挂在树杈上，好像
是个陷阱（disarm）。\n",
		"bush": "茂密的矮树丛在地上交织错生，使人几乎迈不开脚步。你仔细俯下身一看，
树丛中隐藏着两条黑色的藤蔓，一头铺在地上，另一头挂在树杈上，好像
是个陷阱（disarm）。\n",
		"vine": "茂密的矮树丛在地上交织错生，使人几乎迈不开脚步。你仔细俯下身一看，
树丛中隐藏着两条黑色的藤蔓，一头铺在地上，另一头挂在树杈上，好像
是个陷阱（disarm）。\n",
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1580);
        set("coor/y",640);
        set("coor/z",0);
		set("map","zbwest");
		set("trap",1);
		setup();
}


void 	reset(){
	::reset();
	set("trap",1);
}


void 	init()
{
        add_action("do_disarm","disarm");
        add_action("do_nothing", "");
	add_action("do_look","look");
	add_action("do_chat","chat");        
	add_action("do_emote","chat*");                
	add_action("do_quit","quit");
	add_action("do_climb","climb");
}	

int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg || (arg!="tree" && arg!="树")) 
		return notify_fail("你想爬什么？\n");;
	tell_object(me,"说你不行，你就不行，行也不行，不服不行。\n");
	message_vision("$N抓着树干往上爬了半天，一松手又跌了下来。\n",me);
	return 1;
}

int valid_leave(object who, string dir){
	object another;
	seteuid(getuid());
	
	if(dir == "southeast"){
		if (query("trap")) {
			message_vision(BLU"$N忽然觉得脚下一绊，说时迟那时快，两条藤枝套住了$N的双腿。\n"NOR,who);
			message_vision(BLU"$N一个倒栽葱，大头向下被吊了起来。\n"NOR,who);
			who->start_busy(1000);
			who->set_temp("condition_type",HIW "<倒吊在树上>" NOR);
			call_out("release_trap",60,who);
			return notify_fail("");
        	}			
	}	
	return 1;
}


int 	release_trap(object who) {
	
	if (!who->query_temp("condition_type") || who->is_ghost() || environment(who)!= this_object())
		return 1;
	message_vision(HIG"$N在树上拼命挣扎着，终于。。。。
扑通一声，藤枝经不起$N的重量断裂了，$N重重地落到地上。\n"NOR,who);
	who->stop_busy();
	who->delete_temp("condition_type");
	return 1;
}

int 	do_disarm() {
	object *inv,*players;
	int i;
	
	if (!query("trap"))
		return notify_fail("圈套已经被破坏了。\n");
	message_vision(YEL"$N蹲下身子，小心翼翼地将藤蔓移开。\n"NOR,this_player());
	set("trap",0);
	inv=all_inventory(this_object());
	players=filter_array(inv,(: userp($1) && $1->query_temp("condition_type")==HIW "<倒吊在树上>" NOR :));
	if (players && sizeof(players)>0) 
	for (i=0;i<sizeof(players);i++) {
		players[i]->stop_busy();
		players[i]->delete_temp("condition_type");
		message_vision(HIG"$N脚上一松，重重地落到了地上。\n"NOR,players[i]);			
	}
	return 1;
}


int 	do_nothing(string arg)
{
	if (this_player()->query_temp("condition_type")) {
		tell_object(this_player(),WHT"你被吊在树上一筹莫展，看来只有叫救命了！！！\n"NOR);
		return 1;
	}
	else return 0;
}

int 	do_chat(string arg)	{
	CHANNEL_D->do_channel(this_player(), "chat", arg);
	return 1;
}

int 	do_emote(string arg)	{
	CHANNEL_D->do_channel(this_player(), "chat*", arg);
	return 1;
}

int 	do_look(string arg)		{
    	"/cmds/std/look"->main(this_player(),arg);
    	return 1;
}

int 	do_quit()	{
	if (wizardp(this_player())) {
		this_player()->stop_busy();
		this_player()->delete_temp("condition_type");
		message_vision(HIG"$N脚上一松，重重地落到了地上。\n"NOR,this_player());			
	}
	return 1;
}