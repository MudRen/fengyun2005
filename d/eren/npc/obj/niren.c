inherit ITEM;
void create()
{
	set_name("小泥人" , ({ "small toy" , "toy"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("24dao_ren",1);
		set("unit", "个");
		set("long", "一个用泥捏成的小人，但做工精巧，闪着绿莹莹的光芒，
一看就知道看上去不是一般小孩儿的玩具，泥人的底部
刻着一个“烟”字。\n");
		set("value", 100);
	}
	::init_item();
}



