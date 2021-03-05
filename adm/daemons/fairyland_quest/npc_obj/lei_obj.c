//                标准描述长度示例                                   |
// 雷之国度物品
// by naihe  2002-10-27  于茂名

#include <ansi.h>

inherit ITEM;

string *names=({
    HIC"神力之剑"NOR,
    HIC"点缀之石"NOR,
    HIC"容忍之鞘"NOR,
    HIC"完美的神力之剑"NOR,
    HIC"完美的神力之剑"NOR,
});

string *ids=({
    "sl jian",
    "dz shi",
    "rr shao",
    "wm slzj",
    "wm slzj",
});

string *longs=({
    "这是一把小小的剑，看起来不似是武器。剑柄上还刻有两字：神力。\n看来还要和别的什么部分组合(zuhe)起来才是完整的。\n它上面似乎刻着个细细的名字：",
    "这是一颗光滑的小圆石子，十分美丽。\n它上面似乎刻着个细细的名字：",
    "这是一把空剑鞘，在口子边上刻有两字：容忍。\n它上面似乎刻着个细细的名字：",
    "这是一个雷之国度的宝物——完美的神力之剑。但看起来似乎有些不对劲。",
    "这是一个雷之国度的宝物——完美的神力之剑。\n它上面似乎刻着个细细的名字：",
});

string *units=({
    "把",
    "颗",
    "把",
    "个",
    "个",
});

string *pivotal=({   // a.枢轴的 关键的
    "yes",
    "no",
    "no",
    "no",
    "no",
});

string my_mark,my_color,my_msg,
my_mark="lei",my_color=""HIC"",my_msg="雷之国度";

#include "fyld_obj.h"
