inherit ITEM;

void create() {
	set_name("铁针", ({ "needle"}) );	
	set("long", " 一根铁针。\n");
	set("unit", "根" );
	set("value", 1);
    if( clonep() )
       set_default_object(__FILE__);

}