inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("西迟化生散",({"demon drug","drug"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("unit","盒");
	    set("base_unit","包");
	    set("base_weight",30);
	    set("material","herb");
	    set("no_drop", 1);
		set("long","西方魔教密制的奇药之一，治疗气血损伤灵验无比。
（药效：４０００）");

		set("desc_ext","治疗外伤(use)");	// annie. 
	    
	    set("usage_type","pill");
	    set("heal_type","kee/4000");
	    set("type","cure");
	    set("base_value",0);
	    set("effect",4000);
	    set("field","kee");
	    set("volumn",10);
	}
	set_amount(10);
}

