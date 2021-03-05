// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "雷打石");
        set("long", @LONG
行过两界桥，你发觉自己正站在一块硕大无朋的巨石之下。仰头上望，这
块巨石足足有七丈高下，巍然屹立在道路右手。石顶上纹下一条焦黑的裂缝，
约莫有半人来宽，几近将巨石剖成了两半。从缝隙中看进，只见一片漆黑，浑
然无物；绕到石后，却是草木葱郁，并无异象。
LONG
        );
	set("exits",([
  		"east" : __DIR__"xiangsi",
  		"west" : __DIR__"liangjie",
	]) );

		set("item_desc", ([
		"裂缝" : "裂缝并不宽，其中又是黑黝黝一片，还是不要随便挤进去的好。\n",
		"缝隙" : "裂缝并不宽，其中又是黑黝黝一片，还是不要随便挤进去的好。\n",
		"巨石":	"一块七丈高下的巨石，石顶上纹下一条焦黑的裂缝。\n",
	]) );   

	set("outdoors", "xiangsi");

	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


int do_enter(string arg)
{
	object room, me;
	me = this_player();
	if (!me->query("宿命B/相思_落雷")){
		tell_object(me,"你胡乱向裂缝中钻去，一头撞在石角上，差点没晕了过去。\n");
		return 1;
	}
	if ( me->is_busy() || me->is_fighting()){
		tell_object(me,"你现在正忙。\n");
		return 1;
	}
	tell_object(me,CYN"你依着所见箭头指向，小心翼翼的挤进裂缝之中。\n"NOR);
	room=load_object(__DIR__"bingjing");
	me->move(room);
	return 1;
}


void event_thunder()
{
	object *inv;
	object obj = this_object();
	int i,j,num;

	inv = all_inventory(obj);
	if (!sizeof(inv))
		return;
	set("start",1);
	message_vision(HIY"\n天空中突然传来阵阵隆隆的鸣声，仿佛金乌的七驾马车，正从天幕之中碾\n过。你忍抑不住好奇之心，抬头向天上看去。\n"NOR,inv[0]);
	message_vision(HIR BLK"\n只见天上白练腾空，银蛇乱舞，铅灰色的云层被撕扯开无数条裂纹。\n"NOR,inv[0]);
	message_vision(WHT"\n一道雪亮的光芒忽在天际爆开，你只觉两眼一痛，眼前是一片茫茫白色。\n"NOR,inv[0]);
	j = random(sizeof(inv));
	for (i=0;i<sizeof(inv) ; i++)
	{
		inv[i]->start_busy(6);
		if (i == j)
		{
			tell_object(inv[i],HIW"\n你在白芒一闪间似乎见到有个明显箭头刻在石上直指缝隙，但略一恍惚，\n箭头已然不见，让你怀疑是不是自己看花了眼。\n"NOR);
			if (!inv[i]->query("宿命B/相思_落雷"))
			{
				num = 1 + random(10);
				inv[i]->set("宿命B/相思_落雷",num);
				log_file("riddle/FATE_LOG",
				sprintf("%s(%s) 得到宿命B/相思_落雷 "+num+"。 %s \n",
					inv[i]->name(1), geteuid(inv[i]), ctime(time()) ));
			}
		}
		tell_object(inv[i],MAG"\n还不及有所反应，一声轰然雷鸣就在你耳边炸响，霎时间仿佛天崩地裂，\n无数砂石碎土飞溅击打，落在你的脸上，手上．．．\n"NOR);
		tell_object(inv[i],RED"\n你捂住双眼，趴倒在地，只觉得沙尘石土纷纷覆上，几近将你掩埋。\n"NOR);
		inv[i]->set_temp("block_msg/all",1);
		call_out ("recover",10, inv[i]);
	}
	set("start",0);
	return;
}


int recover (object obj)
{
	if (!obj || environment(obj)!= this_object())	return 1;
		
	obj->delete_temp("block_msg/all");
	tell_object(obj, HIG"\n良久之后，耳中的鸣声渐渐淡去，眼前也开始显现出一丝亮光。你狼狈不\n堪的自地上爬起，抖掉身上的尘土，才发现雷打石上又添了新的焦痕。\n\n" NOR);
	return 1;
}	

int	valid_leave(object who, string dir)
{
//	object me;
	if (dir == "east" && userp(who))
	{
		tell_object(who,CYN"你小心翼翼的踩着草径，向相思岭上行去。\n"NOR);
		who->perform_busy(2);
	}
	return ::valid_leave(who,dir);
}

void init()
{
//	object who = this_player();
	add_action("do_enter", "enter");

	/*
	降低发生难度
	*/
	if (NATURE_D->get_weather() == "雷雨")
//		if (this_player()->query("annie/riddle/moonmaster") == 11 && this_player()->query("combat_exp") >= 1400000 )
			if (!query("start"))
				event_thunder();
//				start(who);



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