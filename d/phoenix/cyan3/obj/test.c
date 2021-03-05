#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("插在山壁上的滑竿", ({ "bamboo stick","stick"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根用以抬人上下山路的滑竿，令人惊讶的是它竟有一头\n深陷在坚硬的山壁里，或许你可以试着拉(pull)一拉它。\n");
		set("unit", "把");
		set("value", 0);
	}
	::init_item();
}



void init()
{
	add_action("do_pull","pull");
}

int do_pull(string arg)
{
	object bamboo,me = this_player();
	string msg;
	if (!arg)
		return notify_fail("你要拉什么？\n");
	if (!bamboo = present(arg,environment()))
		return notify_fail("你要拉什么？\n");
	if (bamboo != this_object())
		return notify_fail("你要拉什么？\n");
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	me->perform_busy(3);
	message_vision(CYN"$N双手握住滑竿，脚蹬石壁，大喝道：起！\n"NOR,me);
	msg="滑竿似乎向外移了一点．．．";
	if (me->query_str() < 30)
		msg="可是滑竿动也不动，羞得$N满脸通红。";
	if (me->query_str() < 50)
		msg="滑竿上下摇晃了两下又恢复原状，羞得$N满脸通红。";
	if (me->query_str() < 70)
		msg="滑竿似乎有点儿松动的迹象，但$N的力量显然还是不够。";
	if (me->query("force") < 100)
		msg="可是$N显然已经筋疲力竭了，滑竿没有一点松动的痕迹。";
	message_vision(CYN+msg+"\n"NOR,me);
	me->add("force",-me->query("force") / 3);
	if (me->query("force") < 0) me->set("force",0);
	return 1;
}