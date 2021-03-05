// medicine.c
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("观音像",({"guan yin"}));
        set_weight(6000);
	set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "一尊观音像，据传跪拜（knee）以后，领悟武功会突飞猛进．\n");
	    set("unit","尊");
	    set("value", 200);
	}
}

void init()
{
	add_action("apply_effect","knee");
}

int apply_effect()
{
	int value = 20;
	int diff;

	if(this_player()->is_fighting())
	    return notify_fail("战斗中怎么能跪拜观音？\n");
	
	if (this_player()->is_busy())
		return notify_fail("你现在正忙。\n");
		
	if (this_player()->query("kee")<500)
		tell_object(this_player(),HIW"再磕下去要死人了！！！"NOR);
		
	message_vision("$N＂噗嗵＂一声，跪倒在观音像前，恭恭敬敬地磕了三个响头！\n",this_player());
	
	this_player()->receive_damage("kee",200);
	this_player()->start_busy(3);
	
	if (this_player()->query("class")=="shaolin")
	if (!random(100)) {
		this_player()->set("vendetta/shaolin",0);
		tell_object(this_player(),WHT"佛祖终于原谅你了。。你这个不知悔改的少林败类。。。欢迎再来。\n"NOR);
	}
	
	return 1;
}


