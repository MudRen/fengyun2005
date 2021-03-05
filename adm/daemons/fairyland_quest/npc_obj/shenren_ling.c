//                标准描述长度示例                                   |
// 神人令  ， 持此令可令NPC不再攻击自己。
// by naihe  2002-10-28  于茂名
// 本来写了为了测试时用，但想想，加入游戏内也是非常有意思呀。。。
// naihe 05-9-4 12:27 强化了，持令者可躲避来自各方面的一切攻击行为，
//       包括NPC、玩家攻击；驱逐、发呆旗之类的攻击等。

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIY"神"HIM"人"HIR"令"NOR, ({"shenren ling","ling"}));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);

    else
    {
        set("long", "这是一个「神人令」，它能散发神圣之气，让诸邪恶魔等不敢攻击你。\n");
        set("unit", "个");
        set("value", 0);
    }

    set("hj_game/obj","shenren ling");
    //setup();

    call_out("delete_me", 3 );
    // 发现未知bug。所以必须调用此函数，而任何复制此物品的主端，都需要以 waiting_delete()
    // 来设置数值。
}


// 其他地方复制此文件时，必须启动本函数，设置删除时间。
// 不允许有以前的“巫师用”的情况。无论如何，都要定期删除。
void waiting_delete( int del_time )
{
    if( !del_time ) del_time = 3;
    if( del_time > 600 ) del_time = 600;
    // 最多 10 分钟要删除。

    set( "for_wiz_check_delete_time", del_time ); // 查询时可以知道该令是否在延迟 delete 中
    remove_call_out( "delete_me" );
    call_out("delete_me", del_time );
}

void delete_me()
{
    if( !environment(this_object()) ) return;
    message_vision("$N忽地闪出耀眼光芒，随即消失不见了。\n",this_object());
    destruct(this_object());
}
