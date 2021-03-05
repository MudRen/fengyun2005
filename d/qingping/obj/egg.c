//XXDER
inherit ITEM;
void create()
{
        set_name("小鸟蛋", ({ "bird egg", "小鸟蛋"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个上面有花纹的小鸟蛋。 \n");
                set("value", 100);
        }
}

