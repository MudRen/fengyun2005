// medicine.c

inherit MEDICINE;


void create()
{
	set_name("云南白药",({"baiyao"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","一包云南白药，可以用来治疗100点外伤 。\n");
	    set("unit","盒");
	    set("base_unit","包");
	    set("base_value", 300);
	    set("base_weight",60);
	    set("field","kee");
	    set("type","cure");
	    set("effect",100);
	    set("heal_type","kee/100");
	    set("usage_type","pill");	
	    set("volumn",5);
	}
	set_amount(5);
}

