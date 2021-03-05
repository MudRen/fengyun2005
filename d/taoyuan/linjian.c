#include <ansi.h>
inherit __DIR__"no_killing_place";
void create()
{
        set("short", "山林");
        set("long", @LONG
山林茂密，你脚下的柔软细草恰可没足，耳边有啾啾鸟语，鼻中又嗅着花草幽
香，透过林间，隐约可见北方农家的炊烟，远远的好象有上十余只猴儿在林间跳跃
相戏，真是一片人间仙境。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"road2",
        "east": __DIR__"milin",
        "south" : __DIR__"linjian1",
    ]));

	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

/*
void init(){
	int i, dayTime;
	mixed *local;
	i = NATURE_D->get_season();
	local = NATURE_D->get_current_time();
	dayTime = local[5];
	if((i = 1 || i = 4) && (dayTime > 330 && dayTime < 370) && NATURE_D->get_weather() == "晴") {
		remove_call_out("fog");
		call_out("fog", random(40), this_player());
	}
}
*/


void init_scenery()
{
        if (NATURE_D->get_weather() != "晴") return;
        remove_call_out("fog");
        call_out("fog",1);
}

void fog(object me){
	object *inv, *players;
	int i, num = 1+random(10);
	inv = all_inventory();
    	players = filter_array(inv, (: interactive($1) :));
	message("vision", MAG"乳白色的晨雾，弥漫了林间大地，在阳光的照耀下闪烁着迷人的紫色。\n"NOR, players);
	for(i=0; i<sizeof(players); i++) {
		if (!players[i]->query("宿命B/桃源_晨雾")) {
			players[i]->set("宿命B/桃源_晨雾",num);
			log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到宿命B/桃源_晨雾 "+num+"。 %s \n",
				players[i]->name(1), geteuid(players[i]), ctime(time()) ));
		}
	}   
}


