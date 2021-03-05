
inherit ITEM;
void create()
{
	string *name=({"条"});
	string *num = ({"四","五","六","九"});
	set_name( num[random(4)]+name[random(1)] , ({ "majiangpai tiao","majiangpai","tiao"}) );
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

