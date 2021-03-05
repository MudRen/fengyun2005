inherit EQUIP;
void create()
{
        set_name("面具", ({ "mask" }) );
        set_weight(600);
        set("long","一件精致的面具，竟然就是死去的武当老掌门的形貌。\n");
                set("unit", "件");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "mask");
		set("fakegender", "男性");
                set("armor_prop/id", ({"wudang master"}) );
                set("armor_prop/name", ({"武当老掌门"}) );
		set("armor_prop/short", ({"武当老掌门(wudang master)"}) );
                set("armor_prop/long", ({"一个面色苍白的老人，眉目间却神光炯炯。\n"}) );
                set("wudang_skinmask",1);
}
