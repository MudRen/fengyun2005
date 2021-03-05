
inherit ITEM;
void create()
{
	string *name=({"万"});
	string *num = ({"五","七","八","九"});
	set_name( num[random(4)]+name[random(1)] , ({ "majiangpai wan","majiangpai","wan"}) );
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

