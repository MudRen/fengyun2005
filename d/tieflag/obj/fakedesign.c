inherit ITEM;

void create()
{
        set_name("孔雀图", ({ "design"}) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "孔雀翎的设计图纸，但是好像是假的。\n");
                set("unit", "张");
                set("value", 0);
		set("fake",1);
                set("material", "paper");
              }
        ::init_item();
}