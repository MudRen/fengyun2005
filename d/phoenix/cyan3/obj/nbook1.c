
inherit ITEM;
void create()
{
	string *num = ({"四谛经","大方广十轮经","缘本致经","菩萨善戒经"});
	set_name( num[1] , ({ "buddhism book","book"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一本手抄的佛经。\n");
		set("unit", "个");
		set("value", 0);
	}
	::init_item();
}

