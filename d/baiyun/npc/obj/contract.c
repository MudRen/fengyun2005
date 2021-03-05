inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("租船的契约", ({"qiyue"}) );
	set_weight(5);
	set("long","这是张船行与雇主签订的租用船只的合同。\n");
	set("unit", "张");
	set("value", 0);
	::init_item();
}
