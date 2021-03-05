
inherit ITEM;

void create()
{
	set_name("晶石", ({ "stone" , "晶石"}) );
	set_weight(500);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("prep", "under");
		set("long", "白色的晶石在天光下闪著迷人的色彩\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


