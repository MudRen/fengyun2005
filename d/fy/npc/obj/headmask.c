inherit EQUIP;
void create()
{
        set_name("武当老掌门的面具", ({ "skinmask" }) );
        set_weight(600);
                set("unit", "个");
                set("value", 0);
                set("material", "cloth");
		set("oldmastermask",1);
                set("armor_type", "mask");
		set("fakegender", "男性");
                set("armor_prop/id", ({"wudang master"}) );
                set("armor_prop/name", ({"武当老掌门"}) );
                set("armor_prop/short", ({"武当老掌门(wudang master)"}) );
}
