#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "树干尽头");
        set("long", @LONG
到了这里，你惊觉去路已尽，粗大的枝条渐渐收细，在林间拂过的风里微微摆
动。不远处是一片古树顶盖，看起来甚是结实，却离开你直有三五丈远。边上一根
粗藤自树顶悬垂下来，或可以借以飞渡，却也是万分危险。
LONG
        );
	set("exits",([
  		"down" : __DIR__"maze2/exit",
	]) );
	// nothing
	set("item_desc", ([
		"粗藤": "这条粗藤看起来很结实，或许可以借之飞渡(swing)。\n",
		"藤": "这条粗藤看起来很结实，或许可以借之飞渡(swing)。\n",
		"vine": "这条粗藤看起来很结实，或许可以借之飞渡(swing)。\n",
	]) );
	set("no_fly",1);
	set("vine",1);
	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",100);
	set("outdoors", "bashan");
	setup();
}

void init()
{
	add_action("do_swing","swing");
}

int do_swing(string arg)
{
	object me = this_player(),env=this_object();
	if (!arg)
		return notify_fail("你要荡什么？\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你现在正忙。\n");
	if (!query("vine"))
		return notify_fail("粗藤现在正飘荡在半空中。\n");
	
	add("swing",2);
	if (query("swing") == 2)
		message_vision(CYN"$N扯了扯粗藤，用双手紧紧抓住，深深的吸了口气，作势欲起。\n"NOR,me);
	else
	{
		message_vision(CYN"$N站到另一边，也用双手紧紧抓住粗藤，深深的吸了口气。\n"NOR,me);
		set("vine",0);
	}

	call_out("do_next",2,me,env);
	me->perform_busy(5);
	return 1;
}

int do_next(object me,object env)
{
	if (!me || environment(me) != env)
		return 0;

	if (query("swing") == 2)
	{
		set("vine",0);
		message_vision(CYN"$N攀紧藤条，用力在树干上一蹬，向对面直荡而去。\n啊啊啊．．．哦哦哦哦哦哦．．．啊啊啊！！\n\n"NOR,me);
		call_out("do_failed",2,me,env);
		return 1;
	}

	add("swing",-1);
	if (query("swing") == 3)
		message_vision(CYN"$N攀紧藤条，用力在树干上一蹬，向对面直荡而去。\n啊啊啊．．．哦哦哦哦哦哦．．．啊啊啊！！\n\n"NOR,me);
	else
		message_vision(CYN"$N见藤条去势已竭，使巧力向来时树干虚拍一掌，\n啊啊啊．．．哦哦哦哦哦哦．．．啊啊啊！！\n\n"NOR,me);

	call_out("do_succ",2,me,env);
	return 1;
}

int do_failed(object me,object env)
{
	object room;
	room = find_object(__DIR__"maze2/entry");
	if (!room)
		room = load_object(__DIR__"maze2/entry");
	if (!me || environment(me) != env)
		return 0;
	set("vine",1);
	set("swing",0);
	message_vision(CYN"不到半路，藤条去势就竭，$N双手一滑，从林木间直坠下去，\n啊啊啊．．．哦哦哦哦哦哦．．．啊啊啊！！\n"NOR,me);
	me->move(room);
	message_vision(CYN"\n$N一路上压坠了无数细枝弱叶，翻滚着从半空里坠了下来。\n\n"NOR,me);
	me->set_temp("last_damage_from","从数十丈高的树顶跌下去摔死了。");
	me->receive_wound("kee",3000);
	return 1;
}

int do_succ(object me,object env)
{
	object room;
	room = find_object(__DIR__"churoom_2");
	if (!room)
		room = load_object(__DIR__"churoom_2");
	if (!me || environment(me) != env)
		return 0;
	set("vine",1);
	set("swing",0);
	message_vision(CYN"藤条飞速的向古树顶盖掠去．．\n\n"NOR,me);
	me->move(room);
	message_vision(CYN"藤条自古树顶盖上直掠而过，$N双手一松，稳稳当当的落到了树顶之上。\n\n"NOR,me);
	return 1;
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

