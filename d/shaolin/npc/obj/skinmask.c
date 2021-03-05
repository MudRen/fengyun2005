inherit EQUIP;
void create()
{
        set_name("蒙面巾", ({ "dongying-cloth" }) );
        set_weight(600);
                set("unit", "块");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "mask");
		set("fakegender", "男性");
                set("armor_prop/id", ({"mysterious figure"}) );
                set("armor_prop/name", ({"神秘的人物"}) );
                set("armor_prop/short", ({"神秘的人物(mysterious figure)"}) );
}
