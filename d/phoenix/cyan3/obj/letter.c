#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("草草书就的信", ({ "letter", "信"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("value", 0);
                set("long","
这是一封草草书就的信函，上面有清秀的字迹写著＂冢直原先生亲启＂。
你有些想要撕开(tear)来看个究竟。\n\n"NOR);
        }
	::init_item();
}

void init()
{
  	if(this_player()==environment()){
		add_action("do_tear","tear");
	}
}

int do_tear(string arg)
{
	object	me, ob;
        if(arg != "letter" )    return 0;
	me = this_player();
	ob = this_object();
	message_vision("$N将$n的封口撕开，取出了其中的信笺。\n", me, ob);
	set_name("被撕开的信", ({ "letter", "信"}) );
	set("long","一封已经开了封的信封，里面的信笺中详细记载了中原各派与神教的计划。\n你越看越是心惊，若这封信落到倭人手里．．．\n");
	REWARD_D->riddle_done(me,"密信",0,1);
	remove_action("do_tear","tear");
	return 1;
}
