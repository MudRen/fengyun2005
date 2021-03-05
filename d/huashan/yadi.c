#include <ansi.h>
inherit ROOM;
string flower();
string deadwolf();

void create()
{
        set("short", "山崖底");
        set("long", @LONG
山崖，在这里洒下了它灰暗的影子。异常的安静让你不由自主心神高度紧张，
经年累月不知到有多少人和野物掉到这里了，四处堆满了白骨，白骨堆中，生长着
一些杂草，有些还开出了鲜艳的花朵。
LONG
        );
	set("item_desc", ([
		"cliff" : "山崖虽然陡峭，却长满了长藤，可让人攀爬（ｃｌｉｍｂ）。\n",
		"山崖" : "山崖虽然陡峭，却长满了长藤，可让人攀爬（ｃｌｉｍｂ）。\n",	
		"grass" : (: flower :),
		"杂草" : (: flower :),
		"flower": (: flower :),
		"花朵":   (: flower :),
		"白骨": (: deadwolf :),
		"skeletons": (: deadwolf :),
		"skeleton": (: deadwolf :),
	]));
    	set("flower_amount", 3);
    	set("jade_bottle", 1);
    	set("outdoors", "huashan");

	set("coor/x",-5);
	set("coor/y",-40);
	set("coor/z",-45);
	setup();

}

void init(){
	add_action("do_climb", "climb");
	add_action("do_pick", "pick");
	add_action("do_search", "search");
}

string flower(){
	object me;
	int i;
	
	me = this_player();
	i = NATURE_D->get_season();
	if(i == 2 && query("flower_amount") > 0) {
		tell_object(me, "白骨堆里，杂草丛中开着一朵鲜红的小花，显得那么触目惊心（ｐｉｃｋ　ｆｌｏｗｅｒ）。\n");
	} else if(i == 4){
		tell_object(me, "白雪覆盖下仍然有几块白骨及黄色的杂草露出。\n");	
	} else {
		tell_object(me, "白骨堆里生有几丛翠绿欲滴的杂草。\n");
	}
	return "";	
}

string deadwolf()
{
	object me,obj;
	me = this_player();
	tell_object(me,HIW"一堆散乱的白骨，也不知是人是兽，入目只是一片刺眼的白。\n"NOR);
	if( me->query_temp("followcrow")) 
	{
		if (present("deadwolf",me))
		{
			return "";
		}
		tell_object(me,"一具皮破肉烂，脑壳扁扁的死狼在森森白骨中尤为惊心。\n");
		if (!obj = present("deadwolf",this_object()))
		{
			obj = new(__DIR__"obj/deadwolf");
			obj ->move(this_object());
			me->delete_temp("followcrow");
		}
	}
	return "";
}

int do_search(){
	object me, obj;
	int i,j;
	
	me = this_player();
	i = NATURE_D->get_season();
		
	message_vision("$N在白骨堆里，茅草丛中仔细搜寻。\n", me);
	if(i != 4 )
		return notify_fail("茅草长得郁郁葱葱，你什么也没有找到。\n");
	
	j = me->query_kar();
	if(random(j) > 20 && query("jade_bottle")){
		message_vision("$N被荆棘刺了一下，手上渗出血来。\n",me);
		me->receive_wound("kee",200);
		me->set_temp("last_damage_from","乱摸乱动，被荆棘刺死了。\n");
		tell_object(me, "你发现了一个小小的玉瓶。\n");
		obj = new(__DIR__"obj/bottle");
		if(objectp(obj)){
			obj->move(me);
		}
		add("jade_bottle", -1);
	} else {
		tell_object(me, "你什么也没有发现。\n");
	}
	return 1;
}

void reset(){
	::reset();
	if (!random(4))	set("flower_amount", 1);
	if (!random(5))	set("jade_bottle", 1);
}

int do_pick(string arg){
	object me, flower;
	int i;
	
	me = this_player();
	if(!arg || (arg != "flower" && arg != "花")){
		return 0;
	}
	if(me->is_busy() || me->is_fighting()){
		return notify_fail("你正在忙！\n");
	}
	i = NATURE_D->get_season();
	if(i != 2 )
		return notify_fail("季节不对，没有花耶。\n");
		
	if(query("flower_amount") == 0) {
		return notify_fail("已经没有花了。\n");
	}
	message_vision("$N走到白骨丛中，弯腰摘下了一朵鲜红色的小花。\n", me);
	message_vision("$N突然被花刺了一下，手上渗出血来。\n",me);
	me->receive_wound("kee",200);
	me->set_temp("last_damage_from","中了情花之刺而死。\n");
	flower = new(__DIR__"obj/redflower");
	if(objectp(flower)){
		flower->move(me);
	}
	add("flower_amount", -1);
	return 1;
}


int do_climb(string arg){ 
	object me/*, room*/;
	
	me = this_player();
	if(me->is_busy() || me->is_fighting()){
		return notify_fail("你正在忙！\n");
	}
	if(!arg || (arg != "cliff" && arg != "山崖" && arg!="up")) {
		return 0;
	}
	message_vision("$N手脚齐用，攀抓着藤萝沿着崖壁，奋力向上爬去。\n", me);
	me->start_busy(2);
	call_out("fall", 2, me);
	return 1;
}


void fall(object me){
	object room;
	int j;
	if (me->is_ghost() || !me) 	return;	
	j = me->query_skill("move",1);
	if(j+1 <random(40)) {
		tell_object(me, "你脚下一滑，身形向下落去，直摔得七荤八素。\n");
		message("vision", me->name()+ "脚下一个不稳，从崖壁上跌落了下来。\n", environment(me), me);
				me->receive_wound("kee", random(50));
	    		me->receive_wound("gin", random(50));
            	me->receive_wound("sen", random(50));
            	me->set_temp("last_damage_from","从山崖上摔下来摔死了。\n");
	} else {
		message("vision", me->name() + "越爬越高终于翻过了山崖。\n", environment(me), me);
		room = find_object(__DIR__"duanshan");
		if(!objectp(room)){
			room = load_object(__DIR__"duanshan");
		}		
		me->move(room);
		message_vision("$N双手用力一撑，飞身越上了山崖。\n", me);
	}	
	
}
