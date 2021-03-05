#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"藏渊脉"NOR);
	set("long", @LONG
藏渊脉原本另有其名。只数朝前魔教内乱，巴山悬谷中水源断绝，大司祭
飒露以烟靡之法推算出此处为悬谷水脉所聚而助悬谷中百余人口渡过一劫，此
地遂易名为藏渊之脉。
LONG
        );
	set("exits",([
		"north" : __DIR__"66",
		"south" : __DIR__"64",
		"westup" : __DIR__"55",
	]) );

	set("objects", ([	
	__DIR__"npc/san3" : 1,
					]) );

  	set("coor/x",60);
	set("coor/y",50);
	set("coor/z",0);
	set("outdoors", "potboil");
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

    if( skin->query("liquid/remaining") )
        message_vision("$N将" + skin->name() + "里剩下的" + 
                       skin->query("liquid/name") + "倒掉。\n", this_player());

    type="water";
    name="山间雨水";
    container="藏渊水脉";
    drunk_apply = 6;

    message_vision("$N从"+container+"中将" + skin->name() + "装满"+name+"。\n",me);

    if( me->is_fighting() ) me->start_busy(2);
    skin->set("liquid/type", type);
    skin->set("liquid/name", name);
    skin->set("liquid/remaining", skin->query("max_liquid"));
    if(drunk_apply) skin->set("liquid/drunk_apply",drunk_apply);
    
    return 1;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
