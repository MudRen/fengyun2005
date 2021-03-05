// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	object river,stone;
	set("short", "竹间清流");
        set("long", @LONG
走到竹林边缘，一条蜿蜒的小溪流斜横在你的眼前。溪水不深，底下铺着
一层浑圆可爱的卵石，垫着人蹑足而过。水花扑打在溪边的石子上，推挤着向
东面流去，声若玉珠溅碎，悦耳动听。举目望山，隐约可见一角红檐飞挂在青
郁林中，更高处是银妆积雪，在这东南之地甚是罕见。
LONG
        );
	set("objects", ([
		__DIR__"obj/river" : 1,
	]));
	set("exits",([
  		"north" : __DIR__"lvzhu",
  		"south" : __DIR__"huju",
  		"east" : __DIR__"shuixie",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
}

void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("溪水", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/stone2");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/stone2");
		if(stone)
			stone->move(river);
	}
	return;
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	if (dir == "east")
		me->set_temp("annie/gits",1);
	return ::valid_leave(who,dir);
}


void init()
{
	add_action("do_fill", "fill");
}


int do_fill(string arg)
{
    string name, type, container;
	object me,skin,dew;
    int drunk_apply;
	function f;
	
	me = this_player();
	
	
	if (!arg)
		return 0;
	skin = present(arg,me);
	if (!skin)	return 0;
    if( me->is_busy() )
	{
		write("你上一个动作还没有完成。\n");
		return 1;
	}

	if (!skin->query("liquid/name"))
	{
		write("你没有装水的东西啊。\n");
		return 1;
	}

    if( skin->query("liquid/remaining") )
        message_vision("$N将" + skin->name() + "里剩下的" + 
                       skin->query("liquid/name") + "倒掉。\n", this_player());

    type="water";
    name="清溪水";
    container="小溪流";
    drunk_apply = 6;

    message_vision("$N从"+container+"中将" + skin->name() + "装满"+name+"。\n",me);

    if( me->is_fighting() ) me->start_busy(2);
    skin->set("liquid/type", type);
    skin->set("liquid/name", name);
    skin->set("liquid/remaining", skin->query("max_liquid"));
    if(drunk_apply) skin->set("liquid/drunk_apply",drunk_apply);
    
    f = (: call_other, __FILE__, "drink_drug" :);    
    skin ->set("liquid/drink_func", bind(f, skin));  
    
    return 1;
}


int drink_drug(object ob)
{
    tell_object(this_player(),HIG"溪水中带着淡淡的草香。\n"NOR); 
    return 0;
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
