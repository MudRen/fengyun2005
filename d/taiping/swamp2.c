#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "烂泥路");
        set("long", @LONG
沼泽地延伸到四方有好几里远，四周全是潮湿的草地和一片烂泥，上面长着悬
钩子和杂乱的矮树。芦苇很高，长着长长的叶子，开着深褐色绒毛花，桦树的树皮
白白的，精细稀疏的叶子挂在树上。天空中差不多终年都有一层薄雾笼罩着。
LONG
        );
        set("exits", ([ 
		"east": __DIR__"swamp1",
		"west": __DIR__"swamp3",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("toad",3);
	set("coor/x",-30);
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


void reset(){
	set("toad",3);
	return;
}