//                标准描述长度示例                                   |
// 雨之国度物品
// by naihe  2002-10-26  于茂名

#include <ansi.h>

inherit ITEM;

string *names=({
    MAG"晶莹之泪"NOR,
    MAG"敏慧之心"NOR,
    MAG"灵巧之手"NOR,
    MAG"心灵手巧善之泪"NOR,  // 这是假的
    MAG"心灵手巧善之泪"NOR,
});

string *ids=({
    "jy lei",
    "mh xin",
    "lq shou",
    "xlsq szl",
    "xlsq szl",
});

string *longs=({
    "它犹如一颗凝结的泪珠模样，十分美丽。\n看来还要和别的什么部分组合(zuhe)起来才是完整的。\n它上面似乎刻着个细细的名字：",
    "这是一颗红心模样的东西，十分美丽。\n它上面似乎刻着个细细的名字：",
    "这是一只手掌模样的东西，线条美丽，似是女子手掌一般。\n它上面似乎刻着个细细的名字：",
    "这是一个雨之国度的宝物——心灵手巧善之泪。但看起来似乎有些不对劲。",
    "这是一个雨之国度的宝物——心灵手巧善之泪。\n它上面似乎刻着个细细的名字：",
});

string *units=({
    "颗",
    "颗",
    "只",
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
my_mark="yu",my_color=""MAG"",my_msg="雨之国度";

#include "fyld_obj.h"
