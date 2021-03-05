// annie 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
        set_name("白毫", ({ "tea", "bai hao", "baihao" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("long", "深绿色的茶叶上带有银白色的绒毛，闻起来清香扑鼻。
用热水将它冲开，就是一盏好茶。（pour）\n");// 不用晒了...
                set("value", 40);
                set("名茶", 1);
        }
	::init_item();
}

void init()
{
	add_action("do_pour", "pour");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("指令格式: pour <茶叶> in <物品>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("你身上没有 " + what + " 这样东西。\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "里什麽也没有，先装些热水才能冲开茶叶。\n");
	if(ob->query("liquid/name") != "热水")
		return notify_fail("只有＂热水＂才能冲开茶叶。\n");
	if (ob->query("liquid/remaining") > 30)
		return notify_fail("这么一点儿茶叶，怎么够这么多水冲？\n");
	f = (: call_other, __FILE__, "drink_drug" :);
	ob->set("liquid/drink_func", bind(f, ob));
	ob->add("liquid/kuzhu", 1+random(8));
	message_vision("$N将一些" + name() + "放进" + ob->name() 
		+ "，冲成一"+ob->query("unit")+"新茶。\n", this_player());
	ob->set("liquid/name","白毫");
	destruct(this_object());
	return 1;
}

int drink_drug(object ob)
{
	this_player()->apply_condition("kuzhu",
		(int)this_player()->query_condition("kuzhu") 
		+ (int)ob->query("liquid/kuzhu") );
	return 0;
}
