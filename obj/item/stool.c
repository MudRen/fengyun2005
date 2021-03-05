#include <ansi.h>
inherit ITEM;
void create(){

    set_name("石凳", ({ "stool" , "石凳", "deng zi"}) );
    set_weight(2000);
    set_max_encumbrance(8000);
    set("no_get", 1);

    if( clonep() )
        set_default_object(__FILE__);
    else {
    set("prep", "on");
    set("unit", "个");
    set("long", "石凳的表面被磨得十分光滑，看来经常有人坐在这里（ｓｉｔｄｏｗｎ）。\n");
    set("value", 10);
    }
    ::init_item();
}

void init()
{
	add_action("do_sitdown", "sitdown");
	add_action("do_standup", "standup");
	add_action("do_look","look");
}
int do_look()
{
//	object sitdown_person;
	if (query("sitdown_person") && present(query("sitdown_person"),environment(this_object())))
	{
		set("long", query("sitdown_person")->name()+"悠然坐在石凳之上。\n");	
	}else
	{
		set("long", "石凳的表面被磨得十分光滑，看来经常有人坐在这里（ｓｉｔｄｏｗｎ）。\n");
	}
	return 0;
}

int do_sitdown(){
	
	object me;
//	mapping who;
//	int i,j,amount;
	
	me = this_player();
	if(me==query("sitdown_person") || me->query_temp("state/sit")){
		return  notify_fail("你已经坐下了呀！？\n");		
	}
	if(query("sitdown_person")&&present(query("sitdown_person"),environment(this_object()))){
		return notify_fail("石凳上都已经坐了人。。。\n");
	}
	message_vision("$N在石桌边的石凳上坐了下来。\n", me);
	//set("long", me->name()+"悠然坐在石凳之上。\n");
	set("sitdown_person", me);
	me->set_temp("state/sit", 1);
	return 1;
}

int do_standup(){
	object me;
	
	me = this_player();
	if(me==query("sitdown_person")){
		message_vision("$N从石凳上站起身来。\n",me);
		me->delete_temp("state/sit");
		set("sitdown_person",0);
		//set("long", "石凳的表面被磨得十分光滑，看来经常有人坐在这里（ｓｉｔｄｏｗｎ）。\n");
		return 1;
	}
	return 0;
}
