// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "凝露池");
        set("long", @LONG
这凝露池位于半山腰上，原是山顶的雪水溶后经山腹暗道流出而成，因此
一池清水既寒且澈，却正好消尽你一路攀山而来的暑气。池子显是有人照料，
边上砌了一圈白玉石栏，雕花纹络，十分精致，而出水处更是一个含珠龙颈，
清水就自龙口中滴滴落下。（要进皓月可以：ｓ；ｃｌｉｍｂ　ｖｉｎｅ） 
LONG
        );
	set("objects", ([
		__DIR__"obj/pond" : 1,
		__DIR__"npc/leng1" : 1,
	]));
	set("exits",([
  		"south" : __DIR__"xiangsi",
	]) );

	set("outdoors", "xiangsi");
	set("water",100);
	set("dewsoul",1);

	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
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

	if (!query("water"))
	{
		write("凝露池已经干涸了，池中一滴水也没有。\n");
		return 1;
	}

	add("water",-1);

    if( skin->query("liquid/remaining") )
	{
		write(skin->name() + "中还有一些" + skin->query("liquid/name")+"，不要浪费。\n");
		return 1;	//giggle
	}

    type="water";
    name="清池凝露";
    container="凝露池";
    drunk_apply = 6;

    message_vision("$N从"+container+"中将" + skin->name() + "装满"+name+"。\n",me);

	if (!query("water"))
	{
		if (query("dewsoul"))
		{
			message_vision(CYN"凝露池中的最后一滴露水也被$N打空了．．．\n\n"HIC"突然，一滴晶莹剔透的露珠从石嘴中缓缓滚了出来。\n"HIW"露珠在阳光的照耀下幻出七彩的光芒，滴落到干涸的凝露池中。\n"NOR,me);
			set("dewsoul",0);
			dew=new(__DIR__"obj/dewsoul");
			dew->move(present("dew pond"));
		}
		else
			message_vision(CYN"凝露池中的最后一滴露水也被$N打空了．．．\n\n"NOR,me);

		if (present("water",present("dew pond")))
			destruct(present("water",present("dew pond")));
	}

    if( me->is_fighting() ) me->start_busy(2);
    skin->set("liquid/type", type);
    skin->set("liquid/name", name);
    skin->set("liquid/remaining", skin->query("max_liquid"));
    if(drunk_apply) skin->set("liquid/drunk_apply",drunk_apply);
    skin->set("liquid/drink_func", 0);
    
    return 1;
}
 

void reset()
{
	object w;
	::reset();
	set("water",100);	// 100滴，一个人要打空是impossible滴..^^

	if (!present("water",present("dew pond")))
	{
		w = new(__DIR__"obj/water");
		w->move(present("dew pond"));
	}
}