
inherit ITEM;

void create()
{
	set_name("水晶球", ({ "crystal ball" , "水晶球"}) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个晶莹剔透的水晶球，表面好象有一层幽幽的蓝光闪动。\n");
		set("value", 0);

			set("weapon_material",1);
			set("material_level",54);
			set("desc_ext","祭炼武器(54)");

	}
    ::init_item();
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        if( arg != "crystal ball" ) return 0;

        tell_object(this_player(),"你掏出一个" + this_object()->name() + "。\n");

        return 1;
}


