inherit ITEM;

void create()
{
	set_name("小纸条儿", ({ "paper" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一张小纸条儿，其上写著几个语焉不详的文字：\n海狸精狐南。\n　　　　　　　　　 江");
		set("no_split",1);
		set("unit", "张");
	}
	::init_item();
}


// 凝輕·dancing_faery@hotmail.com

