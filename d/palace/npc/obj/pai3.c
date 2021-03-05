inherit ITEM;
void create()
{
	string *name=({"桶"});
	string *num = ({"一","二","三"});
	set_name( num[random(3)]+name[random(1)] , ({ "majiangpai tong","majiangpai","tong"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一只精致的象牙麻将牌\n");
		set("unit", "个");
		set("value", 10);
	}
	::init_item();
}

