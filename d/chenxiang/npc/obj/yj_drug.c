inherit ITEM;

void create()
{
   		set_name( "麻沸散", ({ "mafei san"  }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("unit", "包");
    		set("value",0);
    		set("long","一包小小的中药。\n");
    		set("medman",1);
    		set("real", 1);
    		set_weight(5);
		}
		::init_item();
}