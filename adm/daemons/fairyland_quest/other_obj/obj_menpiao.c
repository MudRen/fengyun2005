//                标准描述长度示例                                   |
// 游戏内门票
// by naihe  2002-11-03  于茂名

inherit ITEM;

int query_autoload() { return 1; }

void create()
{
    set_name("『幻境·遥远传说之起缘·幽灵显现』 的门票", ({"men piao","piao"}));
    set_weight(10);
    if (clonep())
        set_default_object(__FILE__);
    else
    {
        set("long", "这是一张“幻境”游戏的入场门票，凭它你可以入场游戏一次。\n");
        set("unit", "张");
        set("value", 1);
        set("hj menpiao", 1);
    }

   // setup();
}

