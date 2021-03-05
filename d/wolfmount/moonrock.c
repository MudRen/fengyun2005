#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "望月岩");

	set("long", @LONG
这里便是狼山的最高峰望月岩，狼山有一个古老的传说，每当十五月圆之际，
狼山之王便会登上望月岩，在凄迷朦胧的月色中，仰天狂啸不止。此时山中万千孤
狼群集望月岩下附声群啸，雷霆之威令天地为之动容失色。
LONG);

	set("type","mountain");
	set("exits",([
        "westdown":__DIR__"littlesky2",
		"northwest":__DIR__"skyladder",
	]) );
       set("outdoors", "wolfmount");
	set("item_desc", ([
                "望月岩": "这是一块岩石，下面是黑乎乎的万丈深渊，不想受苦的人可以跳下去（ＪＵＭＰ）。\n",
        ]) );
	set("coor/x",80);
	set("coor/y",10);
	set("coor/z",60);
	set("objects",([
     		__DIR__"npc/qidiao":1,
    	]) );
	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( userp(me) && dir=="westdown" && ob=present("qidiao zhan", this_object()) ) 
        {
                if( me->query("class") != "wolfmount" && !me->query_temp("marks/狼山游客") )
                {                
                        return notify_fail(ob->name()+"身形一闪，拦住去路，粗声喝道：＂此处乃我狼山重地，请回！！！\n");
		}
	}
	return 1;
}

int do_jump(string arg)
{
        object 	me;
	int	cor;
	object  room;

	if(!arg || arg != "down") 
	{
		write("你要跳向哪里？\n");
		return 1;
	}
	me = this_player();
    cor = (int)me->query_cor();
	
	if(cor < 30) 
		message_vision(HIY"\n$N战战兢兢望了望山下，觉得不妥，又赶紧收回脚来。。\n"NOR, me);
	else {
		message_vision(HIY"\n$N咬了咬牙，双眼一闭，纵身跳了下去．．．．．．\n"NOR, me);
		message_vision(HIR"＂扑通＂一声，$N摔到崖底，剧烈的震荡使$N昏了过去．．\n"NOR,me);
		me->unconcious();
		room = find_object(__DIR__"wolfmud");
		if(!objectp(room)) room= load_object(__DIR__"wolfmud");
		me->move(room);
	}
	return 1;
}
