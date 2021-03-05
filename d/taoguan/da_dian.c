#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "上清殿");
	set("long", @LONG
正面是三清的金身塑像。塑像前的神桌上摆着各式水果和一座小铜炉，铜炉里
插着三支点着了的香。左右面墙上都没有任何东西，却是刷得很白。大殿的正中是
一座炼丹炉，一位貌似仙人的道士正在炼丹。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"south" : __DIR__"da_yuan",
		"northwest" : __DIR__"stoneroad",
	]));
        set("valid_startroom", 1);
	set("objects", ([
                __DIR__"npc/up_taoist" : 2,
            	"/obj/specials/ding/ding_sq" : 1,
                __DIR__"npc/taolord" : 1,

 	]) );
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


int	valid_leave(object me, string dir){
	object ding;
	if (me->query_temp("maze/ding_talk_1")) {
		if (ding = present("master ding",this_object())) {
			message_vision(HIC"
丁乘风下定决心道：也罢。。施主尚能舍身取义，贫道还有什么舍不得呢？
施主请留步片刻！

丁乘风站起身，绕着金吾之鼎疾走起来。 

丁乘风一手执着桃木剑，一手掐指，口中念念有辞，须发上扬，道袍迎风而振。 
“咄！”丁乘风猛一回身，木剑直刺$N的眉尖，$N但觉浑身仿佛雷击般一震。 \n\n"NOR, me);
			me->unconcious();
			me->delete_temp("maze/ding_talk_1");
			me->set_temp("maze/ding_talk_2",1);
			ding->event2(me,1);
			return notify_fail("");
		}
	}
	return 1;
}
 
