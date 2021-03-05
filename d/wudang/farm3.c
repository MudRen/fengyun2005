
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "庄稼地");
	set("long", @LONG
一块绿油油的麦田。田中半人高的麦杆儿随风而动，正如江湖中的你，随著江
湖之中汹涌的波涛，四处飘摇。你想到江湖中的无奈,不禁沧然泪下。
LONG
	);
	set("exits", ([
  		"north" : __DIR__"farm3",
  		"south" : __DIR__"farm1",
  		"east" : __DIR__"farm3",
  		"west" : __DIR__"farm7",
	]));
	set("outdoors", "wudang");
	set("coor/x",-25);
	set("coor/y",60);
	set("coor/z",-50);
	setup();


}
void init()
{
	add_action("do_throw","throw");
}

int wind_blow(object me)
{
	object room;
	string weather;
	room = this_object();
	weather = NATURE_D->get_weather();
	
	if(weather != "微风" && weather != "阵风" && weather != "狂风" ) 
		return 1;
	message("vision",HIG"
    阵阵微风拂过，如果将什么树叶之类的抛(throw)在空中的话，一定会随
风飘去，你的一生，是否也如这树叶一般，随风飘荡？\n"NOR,room);
	return 1;
}

int do_throw(string arg)
{
	string leaf_name, weather;
	object leaf,ob;
	int num= 1+random(10);
	
	ob = this_player();
	
	if(!arg) return notify_fail("你要抛什么？\n");
	leaf = present(arg, this_player());
	if(!leaf)
		return notify_fail("你没有这个东西呀？\n");
	if(!leaf->query("castable"))
		return notify_fail("这个东西抛不起来。\n");
	weather = NATURE_D->get_weather();
	if(weather != "微风" && weather != "阵风" && weather != "狂风" ) 
		return notify_fail("现在没有风，抛不起来。\n");
	if(this_player()->query("age")>13 || this_player()->query("宿命B/武当_枫叶",1))
		return notify_fail("你已经不是小孩子了。\n");
	leaf_name=leaf->query("name");
	message_vision("$N将一片"+leaf_name+NOR"抛在风中，慢慢的飘走了。\n",this_player());
	if(leaf_name==HIR"枫叶"NOR)
	this_player()->set("宿命B/武当_枫叶", num);
	log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到宿命B/武当_枫叶 "+num+"。 %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	destruct(leaf);
	return 1;
}
		

void init_scenery()
{
        remove_call_out("wind_blow");
        call_out("wind_blow",1);
}
