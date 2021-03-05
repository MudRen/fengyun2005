inherit ITEM;

void create()
{
        set_name("明月心的心", ({ "heart of mingyue" }) );
				set_weight(400);
				if( clonep() )
					set_default_object(__FILE__);
				else {
		            set("unit", "颗");
                set("long", "明月有心，奈何风云无情。\n");
								set("rigidity", 300);
                set("value", 100);
								set("weapon_material",1);
								set("material_level",135);
								set("desc_ext","祭炼武器(135)");

			}
    	::init_item();
}
