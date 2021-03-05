// medicine.c

inherit MEDICINE;
#include <ansi.h>
int eat_fun();

void create()
{
    	set_name(RED"九花玉露丸"NOR,({"yuluwan","wan"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    	set("long",
"传说此药乃是采集每日晨曦时九种鲜花花瓣上的露水调制而成，外呈朱红
色，清香袭人，养精蓄锐，功效不凡。可以用来治疗2500点精力损伤。\n");
	    	set("base_unit","颗");
	    	set("unit","包");
	    	set("base_weight",60);
        	set("base_value", 20000);
	    	set("type","cure");
	    	set("field","gin");
	    	set("effect",2500);
	    	set("heal_type","gin/2500");
	    	set("usage_type","pill");	
	    	set("use_func",(: eat_fun() :));
	    	set("volumn", 1);
	}
	set_amount(1);
}


int 	eat_fun() {
    	message_vision("$N小心翼翼咽下一颗九花玉露丸，但觉清爽无比，精神陡然一振。\n",this_player());
	return 1;
}


