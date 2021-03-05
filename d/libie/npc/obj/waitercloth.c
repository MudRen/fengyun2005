inherit EQUIP;
void create()
{
        set_name("布衣", ({ "waiter cloth","cloth" }) );
        set_weight(1000);
                set("unit", "件");
                set("value", 0);
                set("material", "jade");
                set("armor_type", "cloth");
		set("fakegender", "男性");

                set("armor_prop/id", ({"Waiter"}) );
                set("armor_prop/name", ({"店小二"}) );
                set("armor_prop/short", ({"店小二(Waiter)"}) );
                set("armor_prop/long",({"
一个跑堂的店小二\n"}) );

		set("离别钩_装成店小二",1);
}
