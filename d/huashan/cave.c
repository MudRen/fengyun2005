#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "毛女洞");
        set("long", @LONG
毛女洞传说是毛女隐遁栖身处。毛女为秦始皇宫女，因避骊山殉葬之灾，负
琴与秦宫役夫相携逃入华山。后业经高士指点，饥食松柏籽，渴饮清泉水，致使
体生绿毛，行步如飞。据说山客猎师世代都有人看见过她，而当夜深人静时，仍
然可以听到毛女洞如泣如诉的琴声。
LONG
        );
    set("exits", ([ 
  		"northdown" : __DIR__"shaluo",
	]));
	set("listen", 0);
	set("music", 0);
    set("indoors", "huashan");
	set("coor/x",-10);
	set("coor/y",-5);
	set("coor/z",10);
	setup();
}

void init(){
//  mixed *local;
//  int dayTime;

/*  if(!NATURE_D->is_day_time()){
		local = NATURE_D->get_current_time();
		dayTime = local[5];
    	 if(dayTime > 1200 && NATURE_D->get_weather() == "晴") {
    		call_out("make_sound", 20, this_player());
    	}
    }*/
    
	add_action("do_listen", "listen");
}


void init_scenery()
{
        call_out("make_sound",1);
}


int make_sound(){
		tell_room(this_object(),CYN"一阵悠悠的琴声不知从何处传来，你凝神聆听（ｌｉｓｔｅｎ），想找出声音的来源。\n"NOR); 	
		call_out("music_gone", 30);
		set("listen", 1);
}

void music_gone(){
	set("listen", 0);
}

int do_listen(){
	object me;
	me = this_player();
	if(query("listen")){
		message_vision("\n幽远的琴声在夜色中如泣如诉，你循着琴声仔细寻找，发现声音似乎从洞顶传来。\n",
				me); 
		me->apply_condition("music", random(10));
		return 1;
	}	
	tell_object(me,"你坐下来静静的听了听，只有蟋蟀的叫声。。。。\n");
	return 1;
}