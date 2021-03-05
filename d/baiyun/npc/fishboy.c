#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("渔童", ({ "fish boy","boy" }) );
        set("gender", "男性");
        set("age", 11);
        set("title", "无忧无虑");
    set("long","赤着脚丫，唱着童谣，在碧海黄沙上自由自在的嬉戏玩耍，\n快乐的时光啊，一去不返。\n");
        set("chat_chance", 1);
        set("chat_msg", 
           ({
"渔童歪歪扭扭地在海滩边嬉戏，齐声唱着歌谣：\n"+CYN
"          白云岛上白云仙          琴棋书画傲红尘
          一朝飞升九天外          门下诸徒落凡间\n"NOR,
"渔童擦了擦红通通的鼻子，继续唱道：\n"+CYN
"          一剑东来是孤城          天下无双为王图
          剑胆琴心向来痴          花茵松实从此醉\n"NOR,
            }) );
    set("combat_exp", 5000);
	set("attitude", "friendly");
	setup();
    if (!random(3)) carry_object(__DIR__"obj/goldfishtank");
	carry_object("/obj/armor/cloth")->wear();
}
