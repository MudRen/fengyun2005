
inherit ITEM;

void create()
{
	set_name("青青河边草", ({ "grass" , "青草"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", "青色的水草在河堤上，随风舞动。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

