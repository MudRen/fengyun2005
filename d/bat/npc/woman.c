#include <ansi.h>
inherit NPC;

void create()
{
    set_name("东三娘", ({ "woman" }) );
	set("gender", "女性" );
	set("age", 22);
	set("per", 30);
	set("long", 
"
这窄小的、黑暗的房子，就是她的全部生命，全部世界。 
在这里没有年，没有月，也分不出日夜。
她只能永远在黑暗中等着，赤裸裸的等着，等到她死。
如果你没有任何负疚的话可以(ｅｎｊｏｙ)。
\n"
    );
	set("combat_exp", 300000);
	set("attitude", "friendly");

	setup();
}

void init()
{
	add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
	object me /*, *inv*/;
//	int i;
	me = this_player();
	message_vision("$N的手几乎比男人还粗野，喘息着道：“来呀……$n已经来了，还等什么?\n",
	this_object(),me);
        message_vision("$N内心涌起一种莫名的深深的悲哀．．．．\n", me);
	me->apply_condition("hualiu_poison",10+random(20));
	return 1;

}
