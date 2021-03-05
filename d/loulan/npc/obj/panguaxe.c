#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
	set_name(HIY"盘古开天斧"NOR, ({ "pangu axe", "axe" }) );
	set_weight(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "把");
		set("long", CYN"\n一把巨大的石斧，上面雕刻着九州山川，天下大河，据传乃是盘古\n开天辟地留下的神斧，具有惊天地，泣鬼神之力量。\n"NOR);
		set("value", 0);
		set("material", "stone");
		set("wield_msg", "$N奋起千钧神力，大喝一声，牢牢攥紧$n。\n");
		set("unwield_msg", "$N将手中的$n扛在肩上。\n");
		set("level_required",130);
	}
	init_axe(130);
}