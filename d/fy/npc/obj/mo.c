// 2009 FengYun
// Edit by hippo 2009.11
// 孝道 关联

inherit ITEM;

void create()
{
        set_name("墨", ({ "mo", "书墨", }) );
        set_weight(700);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "文房用具之一。\n");
                set("value", 1000);
                set("color", "黑");
        }
	::init_item();
}