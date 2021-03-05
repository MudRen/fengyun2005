//By clone   6/2001
inherit EQUIP;
void create()
{
        set_name("老山东的面具", ({ "shandong skinmask","skinmask" }) );
        set_weight(200);
                set("unit", "张");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "mask");
		set("fakegender", "男性");
                set("armor_prop/id", ({"faked old shan dong"}) );
                set("armor_prop/name", ({"老山东"}) );
                set("armor_prop/short", ({"老山东(faked old shan dong)"}) );
}
