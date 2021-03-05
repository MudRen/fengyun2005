// weitianpeng.c
#include <ansi.h>

inherit SMART_NPC;

void create()
{
        set_name("叶秀珠", ({ "ye xiuzhu","ye" }) );
        set("gender", "女性" );
        set("title", "峨嵋派 侠女" );
        set("nickname", HIG"三英四秀之"NOR );
        set("long","一个年轻而美丽的少女，窄窄的衣服衬得苗条的身子更加婀娜动人。\n"
                );
        set("attitude", "peaceful");
        set("age", 22);
        set("combat_exp", 200000);
        
        set("inquiry",  ([
               "叶孤城" : "白云城主的岛不大，架子倒不小，我们峨嵋四秀 来了，竟也没个接待的。\n",
               "master ye" : "白云城主的岛不大，架子倒不小，我们峨嵋四秀 来了，竟也没个接待的。\n",
                 "西门吹雪"  :"看孙师妹这些日子恍恍忽忽，定是和这个冷血杀手。。\n",
                 "master ximen"  :"看孙师妹这些日子恍恍忽忽，定是和这个冷血杀手。。\n",
        ])                      );
        set("chat_chance", 1);
        set("chat_msg", ({
                "叶秀珠恨恨道：师傅真是，几十年了峨嵋山还不如小小白云岛气派。。\n",
                }) );
		auto_npc_setup("wang",60,100,0,"/obj/weapon/","fighter_w","nine-moon-sword",1);   
		delete_temp("nine-moon-force_poison");     
        setup();
        carry_object(__DIR__"obj/emeisword2")->wield();
        carry_object("/d/fugui/npc/obj/w_skirt2")->wear();
}
