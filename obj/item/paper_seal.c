// paper_seal.c
inherit COMBINED_ITEM;

void create() {
	set_name("桃符纸", ({"paper seal", "seal", "paper"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是道士们用来画符的符纸，具有封存法力的功用。\n");
		set("unit", "叠");
        	set("base_unit", "张");
        	set("base_weight", 5);
		set("base_value", 20);
		set("fast_grab",1);
		set("volumn",50);
	}
	set_amount(50);
}
