// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", YEL"黄树林"NOR);
    set("long", @LONG
挤出狭窄的山缝，迎接你的是一片奇特的树林。从未见过的各种参天巨木
如列阵般在黑软的淤泥上排布得井然有序，远远看去，犹如墨盘上还未动过的
木棋。仰头上望，但见覆满苍穹的木叶竟无一片苍碧，满满漾着浅浅的鹅黄，
枝条如镀金边，构筑为一种奇异诡谲的美丽。
    不知名的季节，微风。
    金色的光线从树顶中浅浅地透了下来。
LONG
NOR
        );
	set("objects", ([


	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : "path6",
  		"northup" : "forest5",
  		"southup" : "rock",
  		"eastdown" : "path4",
	]) );
	set("area","cyan3");

	set("coor/x",-40);
	set("coor/y",30);
	set("coor/z",70);
	setup();
}

void trigger(object me)
{
	object ob;
	message_vision(CYN"\n你在一片浓重的血腥味里睁开了眼睛，身前几步是一个抱著左臂、神情痛楚的少女，她\n身著的一袭素裙已然划破多处，绵绵浸出的鲜血惊心触目。\n\n",me);
	message_vision(CYN"凤铭心额上密布一层绵密的汗珠，咬着牙道：昭光，切切莫要在他们面前"WHT"暴露身份"CYN"，他\n们．．不知从哪里听来的消息说东瀛与我神教勾结，一见我便痛下杀手。\n\n",me);
	message_vision(CYN"少女气息哽在喉咙，堵住声音，狠咳了几声续道：箜阙．．受了惊吓，我得去把它找回\n来，你．．一个人千万小心。\n\n",me);
	message_vision(MAG"他们．．．．？"YEL"\n你眉心紧皱，看著少女跌跌撞撞的身影消失在黄树林里，身后洒下斑斑点点血迹。\n\n",me);

	tell_object(me,HIY"你的任务改变了！\n"NOR);

	me->set("quest/short", WHT"到"CYN+"凌云顶"+WHT"参加饮血平寇大会"NOR);
	me->set("quest/location", "凌云顶");
	me->set("quest/duration",3600);
	me->set("quest/quest_type","special");
	me->set("quest_time",time());

	REWARD_D->riddle_set(me,"天涯魂梦",1);


	if (present("feng minxin"))
		destruct(present("feng minxin"));

	return;
}


int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (dir != "eastdown" && dir != "southup" )
//		if (REWARD_D->riddle_check(me,"天涯魂梦") == 1) 
			return notify_fail("时间快赶不上了，就别到处乱晃了吧？\n");

	return ::valid_leave(who,dir);
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


