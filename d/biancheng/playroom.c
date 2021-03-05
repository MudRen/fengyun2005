inherit ROOM;
#include <ansi.h>
string gotit();

void create()

{
        set("short", "魁星阁");
        set("long", @LONG
十年前镇上出了个举人，入京前在这儿捐了个魁星老爷。不过这举人还没见到
皇上，就被强盗砍了脑袋，从此再没人光顾。自从万马堂兴起后，这儿就成了牧马
汉子们喝酒取乐，或是摔跤比武的场所。魁星阁的堂上树了两幅大大的屏风，上面
写着：[33m书中自有颜如王，书中自有黄金屋[32m
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"nstreet3",
		]));
        set("objects", ([
        	
		]) );
		
		set("item_desc", ([
			"屏风":		YEL"书中自有颜如王，书中自有黄金屋\n"NOR,
			"pingfeng":		YEL"书中自有颜如王，书中自有黄金屋\n"NOR,
			"王":		(: gotit() :),
		]));
		
        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",0);
        set("thief",1);
		set("map","zbwest");
		setup();
}

string gotit(){
	
	object me;
	
	me = this_player();
	tell_object(me,"你拍拍脑袋想了想，这个“王”字好像不对吧。\n");
	tell_object(me,"你走近屏风仔细看看，不错，原来“玉”字上的那点时间长了被磨掉了。\n");
	me->set_temp("marks/wanma/pingfeng",1);
	if (query("thief"))
		call_out("falling",random(10)+5, me);
	set("thief",0);
	return "";
}


int falling(object me){
	object thief;
	if (!me || environment(me)!=this_object())	return 1;
	
	thief = new(__DIR__"npc/thief");
	if (!thief)	return 1;
	thief->move(this_object());
	
	message_vision("扑通一声，梁上忽然掉下个人来。\n", thief);
	thief->ccommand("say 见鬼见鬼，怎么躲到这里都会被人撞到！！");
	thief->ccommand("say 小子，你的眼力不错么。\n");
	message_vision("$N觉得自己脑后骨似乎被人摸了一下，仔细一看，$n好像又没动过。\n", me, thief);
	thief->ccommand("say 不错，不错，你很像我，你很像我！\n");
	message_vision("$N眼珠一转，转过身去不说话了。\n", thief);
	if (!REWARD_D->riddle_check(me,"神偷天下") && !REWARD_D->check_m_success(me,"神偷天下"))
		REWARD_D->riddle_set(me,"神偷天下",1);
	return 1;
}
	
	
void reset(){
	object sikong;
	
	sikong = present("sikong taoxing");
	if (sikong) {
		message_vision("司空掏星懒洋洋地说：没事儿我就走了。
司空掏星一转身跳上屋梁消失了。\n",sikong);
	destruct(sikong);	
	}
	set("thief",1);
	::reset();
}
	
