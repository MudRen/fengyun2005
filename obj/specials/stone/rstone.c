#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"蛰龙赤丹"NOR, ({"ruby", "red stone"}));
    	set_weight(200);
    	if( clonep() )
       		set_default_object(__FILE__);
    	else {
        	set("unit", "块");
        	set("long", "
一块艳若明霞的红宝石。里面红光跃动，似乎有不熄的火焰。在手里拿得 
久了，竟有灼烧的感觉。\n");
        	set("value", 200);
		set("imbue", 1);
    }
	::init_item();
}

void init(){
    	if(this_player() == environment()){
        	add_action("do_wield", "wield");
    	}
}

int do_wield(string arg){
    	object me;
    
    	me = this_player();
    	if(!arg || arg != "ruby"){
        	return 0;
    	}
    	message_vision("$N把红宝石托在手中。\n", me);
    	environment(me)->tell_exit(me);
    	return 1;    
}


