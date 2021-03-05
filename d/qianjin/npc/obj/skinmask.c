inherit EQUIP;
void create()
{
        set_name("蒙面巾", ({ "black mask" }) );
        set_weight(600);
                set("unit", "块");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "mask");
        set("fakegender", "男性");
                set("armor_prop/id", ({"meihua dao"}) );
                set("armor_prop/name", ({"梅花盗"}) );
                set("armor_prop/short", ({"梅花盗(meihua dao)"}) );
                set("armor_prop/long", ({"这个人脸上蒙着一块漆黑的布巾，看起来鬼鬼祟祟，\n俨然是传说中的梅花盗。\n"}) );
}
