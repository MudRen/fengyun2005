// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
#define FATEMARK "宿命B/黄山_云海"
inherit ROOM;
void create()
{
        set("short", "天都峰");
        set("long", @LONG
天都是三大主峰中最为险峻的一座，古称“群仙所都”，意为天上都会。现在
路边已有依山凿就的石级和铁索围护的登山道，但是仍然令人有“难于上青天”之
感。途中有一石屏风，刻有“天上玉屏”四字，由此处四周眺望，浮云怪峰，山泉
松海，尽收眼底。
LONG
        );
	set("exits", ([ 
		"southdown"  : __DIR__"jiyu",
		"westdown" : __DIR__"yixian",
	]));
	set("objects", ([
		__DIR__"npc/hong" : 1,
		__DIR__"npc/lu" :1,
	]) );
    	set("outdoors", "huangshan");
      	set("coor/x",-50);
      	set("coor/y",40);
	set("coor/z",40);
	setup();
}

void init_scenery()
{
    	if(NATURE_D->get_weather() == "晴")
    	{
		remove_call_out("cloud");
		call_out("cloud", 2);
    	}
}


void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if (random(ob->query("kar"))>15) {
		tell_object(ob,HIW"\n在一时遮天闭日的迷雾之中，你似乎迷失了方向，找不到来路，也找不到去路了。\n"NOR);
		if(ob->query_busy()<3)		ob->start_busy(2+random(2));
		ob->set(FATEMARK, num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到"+FATEMARK+" "+num+"。 %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}

void cloud()
{
//	int i,age;
	object ob = this_object();
	object *ppls;
	function f=(:add_fate_mark:);
	message("vision", HIW"突然间白云象海潮一般涌来，转眼四周都是白茫茫的雾。\n"NOR, ob);
	ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && !$1->query(FATEMARK):));
	if(sizeof(ppls))
		map_array(ppls,f);
}