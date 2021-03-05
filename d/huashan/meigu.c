#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "幽谷");
        set("long", @LONG
此处直壁连云，罕见人烟，四周万簌俱寂，就连极轻微的虫鸟之声都鲜少听
到。入目可见老梅多本，皆似百年之物，虬枝如铁，数棵翠竹随风摇曳，点缀其
间显得刚柔相继，景色脱俗。
LONG
        );
    set("exits", ([ 
		"southwest" : __DIR__"yinxing",
	]));
	set("meishan", 1);
    set("outdoors", "huashan");
	set("coor/x",-1);
	set("coor/y",-48);
	set("coor/z",30);
    	set("objects", ([
		__DIR__"npc/lie" : 1,
	]));   
    
    
	setup();

}

/*
void init(){
	int i;
	object me;
	me = this_player();
	i = NATURE_D->get_season();
	if (i == 4) {
		call_out("do_winter", 1, me);
	}
}

int do_winter(object me) {
	object mei;
	string weather;
	if(interactive(me) && environment(me) != this_object()){
		return 1;
	}
	if (present("li e", this_object()))	return 1;
	if (present("wen shi", this_object()))	return 1;
	if (query("mei_out")) return 1;
			
	message_vision(HIY"\n一阵梅香飘过，香气沁心，令人心脾神骨皆清。\n"NOR, me);
//	weather = NATURE_D->get_weather();
//	if((weather == "雪" || weather == "大雪")&& NATURE_D->is_day_time() 
//			&& !present("wen shi", this_object())) {
		tell_object(me, "梅阴深处似乎有一身影。\n");
		mei = new(__DIR__"npc/meishan");
		mei->move(this_object());
		set("mei_out",1);
//	}
}


void reset()
{

::reset();
if(query("mei_out") && random(4)) set("mei_out",1);
        else set("mei_out",0);
        
} 
*/