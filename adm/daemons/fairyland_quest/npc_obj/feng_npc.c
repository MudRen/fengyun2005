//                标准描述长度示例                                   |
// 幻境游戏内NPC  风之国度的NPC
// by naihe  2002-10-25  于茂名

#include <ansi.h>

inherit NPC;

string *songs1=({
    "在我们古老的国度里",
    "那已经远去的时间、事情，和生命",
    "我仍记得许多让人心动不已的灵物",
    "以及人民那颗自由飞翔的心",
    "别的人们为了这些而嫉妒",
    "渴望我们如鸟般地翱翔天际",
    "渴望我们如诗般轻灵动人",
    "而我们  我们每一个人",
    "从未能够忘却我们的风之国度",
    "那是我们为之自豪的地方。",
});

string *songs2=({
    "人们曾极力找寻",
    "有个神秘而令人向往的国度",
    "那里属于热爱自由",
    "和期待天空的人们",
    "有位年轻的人找到了它",
    "还领会了它世代相传的宝物",
    "年轻人学会了飞翔、行云和把飘云硬化",
    "他毫不自私，把这些都教给了人们",
    "从此以后我们不再只能停留土地",
    "不再担心猛兽侵袭",
    "这种自由的生命  谁不羡慕于心？",
    "年轻人成为了君主",
    "是他让风之国度得到了神迹。",
    "人民永远传诵他的名字：",
    "风之国度的君主  风翔。",
});

string me_guodu,ask_arg,baowu_name,baowu_dir,baowu_other1,baowu_other2,
me_guodu=""HIW"风之国度"NOR"",baowu_name="天马之身",baowu_other1="伸展之左翼",
baowu_other2="伸展之右翼",ask_arg=baowu_name,baowu_dir=__DIR__"feng_obj";

string *me_mark=({"feng","sz zuoyi","sz youyi"});

#include "fyld_npc.h"
