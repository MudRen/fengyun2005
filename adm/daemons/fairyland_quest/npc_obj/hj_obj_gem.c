//                标准描述长度示例                                   |
// 幻境内物品  各族的宝物(本物件不加入列表)
// （需要此类物品，方可获得要寻找的宝物的最重要组合部分）
// by naihe  2002-10-28  于茂名
// naihe 05-9-8 7:57 V1.8 继续更新。修正一个潜在隐患。

#include <ansi.h>

inherit ITEM;


string *names=({
    "蛮野族宝物",
    "猛力族宝物",
    "矮妖族宝物",
    "山怪族宝物",
    "巨人族宝物",
});

string *ids=({
    "manye baowu",
    "mengli baowu",
    "aiyao baowu",
    "shanguai baowu",
    "juren baowu",
});

string *longs=({
    "这是一个蛮野族的宝物，黑呼呼的一团不知道是什么，也不知道有什么用。\n",
    "这是一个猛力族的宝物，黑呼呼的一团不知道是什么，也不知道有什么用。\n",
    "这是一个矮妖族的宝物，黑呼呼的一团不知道是什么，也不知道有什么用。\n",
    "这是一个山怪族的宝物，黑呼呼的一团不知道是什么，也不知道有什么用。\n",
    "这是一个巨人族的宝物，黑呼呼的一团不知道是什么，也不知道有什么用。\n",
});

void setme( int iii )
{
    if( iii == 99 || iii < 0 || iii >= sizeof(names) )
        iii = random(sizeof(names));
    set("iii", iii);
    set_name( names[ iii ], ({ ids[ iii ], "baowu" }) );
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);

    set("long", longs[ iii ]);
    set("unit", "个");
    set("hj_game/obj","the_gem");
    set("no_refresh", 1); // 不被MUD刷掉

    set("value", 1);  // 该物件扔下后不会消失。
}

void create()
{
    setme(99);
 //   setup();
}
