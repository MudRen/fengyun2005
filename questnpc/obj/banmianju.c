inherit EQUIP;
void create()
{
        set_name("青铜面具", ({ "mianju" }) );
        set_weight(1000);
                set("unit", "个");
                set("value", 0);
                set("material", "jade");
                set("armor_type", "mask");
		set("fakegender", "男性");
                set("armor_prop/id", ({"Master ban"}) );
                set("armor_prop/name", ({"班察巴那"}) );
                set("armor_prop/short", ({"班察巴那(Master ban)"}) );
				set("armor_prop/long",({"
没有人的脸上会发出这种青光的，除非他脸上戴着个青铜面具。
这人的脸上就戴着青铜面具，在星光下看来，显得更狰狞而怪异。
他身上穿着的，却是件美丽的绣花长袍，腰带上斜插着三柄弯刀。
惨碧色的刀鞘上，缀满了明珠美玉。\n"}) );
}
