// salt
inherit COMBINED_ITEM;
void create()
{
	set_name("盐巴", ({ "salt rock", "rock" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"这是一块亮晶晶的盐巴，把它溶解在水里（ｐｏｕｒ）就成了盐水，可以用来化冰。\n" );
        set("unit", "包");
		set("base_value", 70);
		set("base_unit", "块");
		set("base_weight", 30);
	}
	set_amount(1);
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
		return notify_fail("指令格式: pour <盐巴> in <装水容器>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("你身上没有 " + what + " 这样东西。\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "里什麽也没有，先装些水酒才能溶化盐巴。\n");
	f = (: call_other, __FILE__, "drink_drug" :);
	ob->set("liquid/drink_func", bind(f, ob));
	ob->set("liquid/name","盐水");
	ob->add("liquid/salt_effect", 10);
	message_vision("$N将一些" + name() + "捏碎，倒进" + ob->name() 
		+ "，摇晃了几下。\n", this_player());
	add_amount(-1);
	return 1;
}

int drink_drug(object ob)
{
	this_player()->apply_condition("salt_drug",
		(int)this_player()->query_condition("salt_drug") 
		+ (int)ob->query("liquid/salt_effect") );
	return 0;
}


