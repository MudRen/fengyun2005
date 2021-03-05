// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
//	int i;
	
    set("short", "观瀑亭");
    set("long", @LONG
一座六方翘角，顶覆绿色琉璃的小亭子，中间摆有一张石桌和四个石凳，坐在
这里，可以远观黄山三大名瀑之一的“百丈泉”，由此看百丈泉，只见清潭，紫云二
峰有飞泉倾泄，势如银河天降，雨少时，如轻纱薄雾，雨足时则如千匹白练，高悬
天际，实在美不胜收。
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"wenquan",
]));
        set("objects", ([
                __DIR__"npc/katai" : 1,
				"/obj/item/stool" : 4,

       ]) );


    set("outdoors", "huangshan");
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",20);
	setup();
}

void init() {

	add_action("do_look", "look");
}

int do_look(string arg) {
	object me;
	int season/*, i*/;
	
   	me = this_player(); 
   	season = NATURE_D->get_season();
   	if(!arg || arg != "waterfall" && arg != "百丈泉" && arg != "瀑布") {
   		return 0;	
	}
	if(!me->query_temp("state/sit")) {
		write("从这里你可以清楚地看到百丈泉。\n");
		return 1;
	}
	if(season == 1 ) {
		write("水似一匹白练从百丈的高崖挂下，在风中抖动着白丝一样的水雾。\n");
	} else if (season == 2 ) {
		write("你坐在这里向亭外的瀑布看去，只见水从百丈的高崖落下，\n");
		write("有如万马奔腾，冲击在崖底的石头上溅起了一片白色的水雾。\n");
		call_out("water_drop", random(30), me);
	} else if (season == 3 ) {
		write("你坐在这里向亭外的瀑布看去，只见水从百丈的高崖落下，\n");
		write("有如万马奔腾，冲击在崖底的石头上溅起了一片白色的水雾。\n");
		call_out("water_drop", random(30), me);
	} else if (season == 4 ) {
		write("水似一匹白练从百丈的高崖挂下，在风中抖动着白丝一样的水雾。\n");
	} else {
		return 0;
	}
	return 1;
}

void water_drop(object me) {
	int kar;
	int num = 1 + random(10);
	kar = me->query_kar();
	if(objectp(me) && environment(me) == this_object()) {
		if(random(40) < kar) {
			tell_object(me, "一阵劲风吹来，几滴冰凉的水露落在了你的脸上。你抬手抹去脸上的水滴。\n");
			message("vision", me->name() + "抬手在脸上抹了一把。\n", environment(me), me);
			if (!me->query("宿命B/黄山_瀑布")) {
				me->set("宿命B/黄山_瀑布", num);
				log_file("riddle/FATE_LOG",
					sprintf("%s(%s) 得到宿命B/黄山_瀑布 "+num+"。 %s \n",
					me->name(1), geteuid(me), ctime(time()) ));
			}
		} else {
			tell_object(me, "一阵劲风吹来，几滴水飘落在亭外地上。\n");
		}
	}
}



int valid_leave(object who,string dir)
{
	if(who->query_temp("state/sit"))
		return notify_fail("你正坐着呢，不能离开！！\n");
	return 1;
}

int invalid_leave(object who)
{
	//if they leave by illegal means like burn sheets, let's clear the stool states
	object *stools;
	if(who->query_temp("state/sit"))
	{
		who->delete_temp("state/sit");
		stools = children("/obj/item/stool");
		for(int i = 0;i< sizeof(stools);i++)
		{
			if (present(stools[i],this_object()) && stools[i]->query("sitdown_person") == who)
			{
				stools[i]->delete("sitdown_person");
				return 0;
			}
		}
	}	
	return 0;
}