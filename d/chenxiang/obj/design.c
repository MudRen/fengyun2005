inherit ITEM;

void create()
{
        set_name("孔雀图", ({ "design"}) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "孔雀翎的设计图纸，上边弯弯曲曲的画了不少符号。\n");
                set("unit", "张");
                set("value", 0);
		set("real",1);
                set("material", "paper");
              }
	::init_item();
}
