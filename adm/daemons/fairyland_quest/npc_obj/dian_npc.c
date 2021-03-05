//                标准描述长度示例                                   |
// 幻境游戏内NPC  电之国度的NPC
// by naihe  2002-10-27  于茂名

#include <ansi.h>

inherit NPC;

string *songs1=({
    "是什么让我们心动不已？",
    "是什么让我们无法舍弃？",
    "是什么让我们惦记如新？",
    "是什么让我们自豪至今？",
    "——难道是我们曾有的  那",
    "无可比拟的巨大财富？",
    "勤劳耐心的美德？",
    "还是  一些我们无法说清的东西？",
    "——不，我说得清",
    "我说得清这一切，因为那是如此简单易明",
    "这一切，答案就是我们的国家",
    "电之国度",
    "它的美丽，将远远超过所有人的想象",
    "而值得人们永远也像我们一般",
    "难以将它忘怀。",
});

string *songs2=({
    "歌声响起的时候",
    "让我想起电之国度的事情",
    "我们本来并不富有",
    "只是安分而勤恳地劳作",
    "从不停息",
    "直到有一天  世界被勤劳的人们所感动",
    "赐予了我们那巨大的宝藏",
    "和那寻得宝藏的人",
    "从此我们不再需要辛苦地日夜劳作",
    "从此我们的日子幸福而充满欢乐",
    "这一切，由我们的君主所带来",
    "他的名字叫  电闪",
    "每一个人都应该记住他",
    "这个让电之国度走向辉煌的人。",
});

string me_guodu,ask_arg,baowu_name,baowu_dir,baowu_other1,baowu_other2,
me_guodu=""HIG"电之国度"NOR"",baowu_name="绿色宝石",baowu_other1="红色宝石",
baowu_other2="蓝色宝石",ask_arg=baowu_name,baowu_dir=__DIR__"dian_obj";

string *me_mark=({"dian","hongse baoshi","lanse baoshi"});

#include "fyld_npc.h"
