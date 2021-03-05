inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("活络秘药",({"drug"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("unit","盒");
	    set("base_unit","包");
	    set("base_weight",30);
	    set("material","herb");
		set("long","中原武林中颇为少见的医疗心神药物。(药效：1500)");

		set("desc_ext","治疗心神(use)");	// annie. 
	    
	    set("usage_type","pill");
	    set("heal_type","sen/1500");
	    set("type","cure");
	    set("base_value",0);
	    set("effect",1500);
	    set("field","sen");
	    set("volumn",5);
	}
	set_amount(5);
}

