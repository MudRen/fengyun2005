inherit ITEM;

void create()
{
        set_name("云雾茶", ({ "tea", "yunwu cha", "云雾茶" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("long", "深绿色的茶叶上带有银白色的绒毛，闻起来清香扑鼻。\n");
                set("value", 200);
                set("名茶", 1);
        }
	::init_item();
}


