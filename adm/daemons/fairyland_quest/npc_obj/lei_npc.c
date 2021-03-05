//                标准描述长度示例                                   |
// 幻境游戏内NPC  雷之国度的NPC
// by naihe  2002-10-27  于茂名

#include <ansi.h>

inherit NPC;

string *songs1=({
    "我要为它传唱",
    "唱那心中永远不灭的故乡",
    "那些人民多么勇敢",
    "多么的如骄阳般热情高涨！",
    "那儿有位名叫雷鸣的勇士",
    "他带领我们打退了山妖、河兽和蛮野族人",
    "带来不再争斗和忧心的日子",
    "多少人民为此得到幸福？",
    "雷之国度为他而骄傲",
    "也将永远记住这一位君主",
    "他的名字",
    "将传遍这茫茫大地的四方。",
});

string *songs2=({
    "那个远远的时空里",
    "那些时空里的的人们",
    "那些人们所在的国家  我热爱的国家",
    "如今已不再复现这世界上。",
    "我纵有如何强大的力量",
    "如何恒久的忍耐",
    "却又如何能够挽回时光？",
    "雷之国度——我只能高声呼喊着这个名字",
    "只期待有哪位勇士",
    "能够寻得失落的宝物",
    "把它从迷境之中寻回。",
});

string me_guodu,ask_arg,baowu_name,baowu_dir,baowu_other1,baowu_other2,
me_guodu=""HIC"雷之国度"NOR"",baowu_name="神力之剑",baowu_other1="点缀之石",
baowu_other2="容忍之鞘",ask_arg=baowu_name,baowu_dir=__DIR__"lei_obj";

string *me_mark=({"lei","dz shi","rr shao"});

#include "fyld_npc.h"
