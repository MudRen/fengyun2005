// medicine.c
inherit MEDICINE;

void create()
{
	set_name("大风丸",({"dafeng"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long","一颗大风丸，可以用来治疗50点心神损伤。\n");
		set("unit","盒");
		set("base_unit","颗");
		set("base_weight",60);
		set("base_value", 300);
		set("type","cure");
		set("field","sen");
		set("effect",50);
		set("heal_type","sen/50");
		set("usage_type","pill");
		set("volumn",5);	
	}
	set_amount(5);
}