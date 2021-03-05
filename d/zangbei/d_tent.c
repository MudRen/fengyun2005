#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "帐篷前");
        set("long", @LONG
较大的池塘边，有叁个华丽的帐篷，帐篷前竟肃立着几个手执金戈，甲胄辉煌
的武士。华丽的帐篷里，不时传出轻盈的乐声和欢乐的笑声，帐篷外执戈肃立的武
士，目光却如鹰一般锐利。
LONG
        );
        set("exits", ([ 
	  	"enter" : __DIR__"d_tentin",
	  	"west": __DIR__"d_oasis",
			]));
	set("objects", ([
		__DIR__"npc/g_wushi":	4,
	]));
	set("item_desc",([
		
	]));
        set("outdoors", "zangbei");
        set("coor/x",-60);
	set("coor/y",310);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

void init(){
	add_action("do_look","look");
}

int do_look(string arg){
	if (arg=="enter") {
		tell_object(this_player(),"帐门低垂，看不清帐内的动静，只隐隐听见喝酒行令之声。\n");
		return 1;
	}
	return 0;
}

int valid_leave(object me, string dir){
	
	object *inv, soldier,*pros;
	int i;
	
	if (!soldier=present("soldier",this_object()))
		return 1;
	
	if (dir == "enter") {
		if (REWARD_D->check_m_success(me,"极乐之星"))	return 1;
				
		if (!me->query("zangbei/龟兹_偷窥成功")) {
			return notify_fail("执戈武士将手中长戈一横：大王宴请宾客，闲人不得入内！\n");
		} else {
			me->delete_temp("last_damage_from");
			message_vision(HIR"$N正要向帐中跨进，金戈闪电般从$N背後刺了过来，红缨闪闪，如毒蛇出穴。\n\n"NOR,me);
			
			inv = all_inventory(this_object());
			for (i=0;i<sizeof(inv);i++) {
				if (inv[i]->query("group_1")!="guizi") continue;
				COMBAT_D->do_attack(inv[i], me, inv[i]->query_temp("weapon"));	
			}
			if (me->query_temp("last_damage_from")) {
				tell_object(me,HIG"\n帐中遥遥传来银铃般的笑声，“看来你光有嘴上的功夫。。。。”\n\n"NOR);
				me->set("zangbei/龟兹_入帐失败",time());
				me->start_busy(1);
				return notify_fail ("");
			}
			
			message_vision(HIG"\n帐中遥遥传来银铃般的笑声，“你能躲得过这一击，就是我们的嘉宾了。”\n\n"NOR,me);
			if (!REWARD_D->riddle_check(me,"极乐之星"))
				REWARD_D->riddle_set(me,"极乐之星",1);
			me->delete("zangbei/龟兹_入帐失败");
			return 1;
		}
	}
	return 1;
}