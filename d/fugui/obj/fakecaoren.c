inherit ITEM;
void create()
{
	set_name("稻草人", ({ "daocao ren","ren" }) );
	set_weight(500);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "个");
		set("long", "一个用来驱赶麻雀的稻草人，面无表情的在风中飘荡。\n");
		set("value", 1);
	}
	::init_item();
}
