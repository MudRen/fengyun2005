inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "后帐");
        set("long", @LONG
后帐很小，帐角用铁钉钉的死死的，只在顶部留一个通气的小孔，中间柱子上
绑着一个十二三岁的男童。面前放着一个铁盆，盆里是几个风干的馒头和一杯浑浊
的水。小童倒在血泊中，已经快断气了。
LONG
        );
        set("exits", ([ 
	  	"south" : __DIR__"camp",
			]));
	set("objects", ([
		__DIR__"npc/sima" : 1,
	]));
	set("indoor","eren");
        set("coor/x",-440);
	set("coor/y",625);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

void init() {
	
	add_action("do_loose", "loose");
}

int do_loose(string arg){
	object me,ob;
	int i;
	me=this_player();
	ob=this_object();
	if (!arg && arg!="司马小烟"&& arg!="sima") {
		tell_object(me,"你想解什么？\n");
		return 1;
	}
	if (!ob=present("sima",this_object())) {
		tell_object(me,"这里没有这个人。\n");
		return 1;
	}
	if (ob->query("loose")) {
		tell_object(me,"他已经被解开了。\n");
		return 1;
	}
	message_vision(YEL"
$N伸手将司马小烟从柱子上解了下来。
	
司马小烟缓缓地滑倒在地上，口中咕噜咕噜地冒出血泡。

司马小烟断断续续地说：谢谢你来救我。我一直以为我父亲是个英雄，
一直希望我长大后能做像他一样的人，没想到。。是这样的结果。"NOR,me);

	if (ob->query("poisoned"))
	message_vision(YEL"	
那泥人中是我父亲留下的断肠丝，中者必死。\n\n"NOR, me);

	message_vision(YEL"
	
他死了，我也要死了，这仇恨就了结了。

司马小烟挣扎着说：我、我知道一个秘密，那、那恶人村其实，
其实没有、没有。。。那，那下面有

呃。。。。。。\n\n"NOR,ob);
	
	ob->die();
	set("poisoned",0);
	
	if (REWARD_D->riddle_check(me,"司马小烟")==4)
		REWARD_D->riddle_done(me,"司马小烟", 30, 1);	
	
	QUESTS_D->special_reward(me,"司马小烟");
	return 1;
}
