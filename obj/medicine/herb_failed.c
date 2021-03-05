inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("腐烂的药草",({"decayed herb", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","一株在水中浸泡得太久以至腐烂的药草，已经看不出本来是什么东西了。\n");
	    set("unit","簇");
	    set("base_unit","棵");
	    set("base_weight",30);
	    set("type","medicine");
	    
	    set("base_value",0);
	    set("heal_type","kee/1");
	    set("usage_type","herb");	
	    
	    set("material","herb");
	    set("level",0);
	    set("effect",10);
	    set("field","kee");
	    set("volumn",1);
	}
	set_amount(1);
}

