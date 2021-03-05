#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("给蓝一尘的信", ({ "letter", "信"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("value", 0);
                set("long","
这是封牛皮信，以火漆封口。似乎可以撕开(tear)，上书：
      
      恭呈 蓝一尘 蓝大侠启\n\n"NOR);
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
	set("long","一封已经开了封的信封，里面的信笺上写着：
 
    家父因先生而死，临终前悲愤悒郁之状，虽经数十载仍历历在目。
铮此际身负血案重任，不敢以私枉公，待案情水落石出之日，便是在下
与先生了结当年恩怨之时。

						杨铮\n");
	
	me->set("timer/libie_letter",time());
	remove_action("do_tear","tear");
	return 1;
}
