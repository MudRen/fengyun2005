inherit ITEM;

void create()
{
        set_name("房屋结算合同", ({ "payoff contract"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张房屋的合同，持此可在自己房屋内执行payoff指令。\n");
                set("value", 100000);
        }
        ::init_item();
}


