inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("自塑雕像", ({ "自塑雕像" , "雕像", "statue"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "座");
		set("long", "达波拉结的四大弟子都松钦巴、玉扎巴、达玛旺秋、帕木竹巴，分别建立了达波噶
举的四大支派。其分别为：噶玛噶举派、蔡巴噶举派、跋戎噶举派、帕竹噶举派。
这座塑像就是纪念帕木竹巴的。\n");
		set("value", 1);
		set("prep","on");
	}
	::init_item();
}

int is_container() { return 1; }


