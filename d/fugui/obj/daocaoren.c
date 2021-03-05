inherit ITEM;
void create()
{
	set_name("稻草人", ({ "daocao ren","ren" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "个");
		set("long", "一个披麻带孝的稻草人，一只手还提根哭丧棒。稻草人胸前麻衣上缝\n了一个纸条子(paper)。风筝的线，就系在稻草人的另一只手上。\n");
		set("value", 1);
	}
	::init_item();
}
