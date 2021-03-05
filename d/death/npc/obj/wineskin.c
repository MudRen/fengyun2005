// waterskin.c
#include <login.h>
inherit ITEM;
inherit F_LIQUID;
string *revive_loc= ({
    AREA_FY"church",
    AREA_GUANWAI"tower",
});

void create()
{
	set_name("牛皮酒袋", ({ "jiudai", "dai" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个牛皮缝的大酒袋，大概装得八、九升的酒。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "还阳酒",
		"remaining": 5,
		"drunk_apply": 6,
	]) );
	::init_item();
}

/*
int do_drink(string arg){
	object me, cloth;
   	int foo;
   	foo=::do_drink(arg);
   	if (!foo) return foo;
   	me = this_player();
	if(query("liquid/name") != "还阳酒"){
		return foo;
	}
   	if(me->is_ghost()){
		me->reincarnate();
		cloth = new("/obj/armor/cloth");
		if(objectp(cloth)) {
			cloth->move(me);
			cloth->wear();
		}
		me->move(revive_loc[random(sizeof(revive_loc))]);
		me->set("startroom", base_name(environment(this_player())));
		message("vision",
                "你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
                "很久了，只是你一直没发觉。\n", environment(me), me);

   }	
  return 1;
}

*/