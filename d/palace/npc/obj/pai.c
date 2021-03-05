
inherit ITEM;
void create()
{
	string *name=({"条","万","桶"});
	string *num = ({"一","二","三","四","五","六","七","八","九"});
	set_name( num[random(9)]+name[random(3)] , ({ "majiangpai"}) );
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

