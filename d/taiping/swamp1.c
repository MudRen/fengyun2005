#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "烂泥路");
        set("long", @LONG
太平镇后有一片很大的沼泽地。这里原来是一个小湖，后来干涸了，就成了这
样。它延伸到四方有好几里远，四周全是潮湿的草地和一片烂泥沼泽，泥炭沼，上
面长着悬钩子和杂乱的矮树。天空中差不多终年都有一层薄雾笼罩着它。
LONG
        );
        set("exits", ([ 
		"east": __DIR__"mroad9",
		"west": __DIR__"swamp2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("toad",3);
	set("coor/x",-20);
	set("coor/y",-90);
	set("coor/z",0);
	set("map","taiping");
	setup();

}

void init()
{
	object me, here;

	me = this_player();
	here = this_object();

	if( random(query("toad"))> 0 && userp(me) && time() - query("last_comeout") > 180
		&& !present("toad",this_object())) {
		set("last_comeout", time() );
		remove_call_out("toad_out");
		call_out("toad_out", 6+random(3)); 
		tell_object(me, "你觉得脚下软绵绵地似乎踩到了什么活物。\n");
	}
}

void toad_out()
{
	object toad, here;
	here = this_object();

	add("toad", -1);
	toad = new("/obj/animal/toad");
	toad->move(here);
	message("vision", YEL"草丛里忽然跳出了一只癞蛤蟆。\n"NOR, here);
	return;
}


