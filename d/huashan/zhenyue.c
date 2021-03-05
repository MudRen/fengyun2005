#include <ansi.h>
inherit ROOM;
string tree();
void create() 
{
        set("short", "镇岳宫");
        set("long", @LONG
此宫依西峰东麓而筑，随崖就势，建筑独特。宫前地是平坦，四周奇峰耸天，
苍松古木遮天蔽日，奇花异草多不胜数，宫前一棵古柏树，平如偃盖，上有青萝长
百尺，古不知年。宫内则有传说生长过千叶白莲的玉井。
LONG
        );
    set("exits", ([ 
	    "northwest" : __DIR__"lianhua",
	]));
	set("item_desc", ([
		"tree" : (: tree :),
		"古柏" : (: tree :),
	]));   
	set("objects", ([
		__DIR__"obj/vine" : 1,
		__DIR__"npc/youke" : 1,
	]));   
    set("outdoors", "huashan");
	set("coor/x",-72);
	set("coor/y",-64);
	set("coor/z",40);
	setup();
}

void init_scenery()
{
	set("amber", 1);    
}

string tree(){
	object me, room;
	me = this_player();
	if(NATURE_D->is_day_time()){
		tell_object(me, "古柏如盖遮蔽了天日，粗糙的树干上挂有淡黄色的松油脂。\n");
	} else {
		if(!random(10)){
			room = find_object(__DIR__"lianhua");
			tell_object(me, HIY"你看到古柏树下有微微的黄光一闪而逝。\n"NOR);
			message("vision", HIY"只见镇岳宫方向闪过一道微微的黄光。\n"NOR, room);
			add_action("do_search", "search");
		} else {
			tell_object(me, "古柏如盖遮蔽了天日，在昏暗的夜光下你什么也看不清。\n");
		}
	}
	return "";
}

int do_search(){
	object me, amber;
	me = this_player();
	if(me->is_busy() || me->is_fighting()){
		return notify_fail("你正在忙！\n");
	}
	message_vision("$N仔细的在古柏下搜寻。\n", me);
	if(query("amber") && !random(10)) {
		tell_object(me, "你在古柏旁看到一颗晶莹剔透的琥珀，你把它拾了起来。\n");
		message("vision", me->name() + "弯腰捡了一个东西揣入怀里。\n", environment(me), me);
		amber = new(__DIR__"obj/amber");
		amber->move(me);
		add("amber", -1);
	} else {
		tell_object(me, "你什么也没有发现。\n");
	}
	return 1;
}
