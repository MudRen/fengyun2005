//XXDER
inherit ITEM;
void create()
{
        set_name("信", ({ "letter", "信"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("value", 0);
				set("long",
"一封用火漆封好的信函，上面写着“神剑山庄主人敬启”。\n"
);
				set("for_xie_test",1);
        }
       ::init_item();
}
 
