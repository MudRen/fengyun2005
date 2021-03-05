inherit ITEM;

void create()
{
        set_name("山茶花", ({ "flower" }) );
				set_weight(400);
				if( clonep() )
					set_default_object(__FILE__);
				else {
		            set("unit", "朵");
                set("long", "巧夺天工，非金非玉，散发着奇异的光彩。\n");
								set("rigidity", 300);
                set("value", 100);
								set("weapon_material",1);
								set("material_level",130);
								set("desc_ext","祭炼武器(130)");

			}
    	::init_item();
}
